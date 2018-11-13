/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/13 02:27:18 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	f_type(int n)
{
	char c;

	c = '\0';
	if (n == S_IFLNK)
		c = 'l';
	else if (n == S_IFREG)
		c = '-';
	else if (n == S_IFDIR)
		c = 'd';
	else if (n == S_IFCHR)
		c = 'c';
	else if (n == S_IFBLK)
		c = 'b';
	else if (n == S_IFIFO)
		c = 'p';
	else if (n == S_IFSOCK)
		c = 's';
	else
		c = '?';
	return (c);
}

char	*f_permission(int n)
{
	char	*perm;

	perm = ft_strnew(11);
	perm[0] = f_type(n & S_IFMT);
	perm[1] = (n & S_IRUSR) ? 'r' : '-';
	perm[2] = (n & S_IWUSR) ? 'w' : '-';
	if (n & S_IXUSR)
		perm[3] = (n & S_ISUID) ? 's' : 'x';
	else
		perm[3] = (n & S_ISUID) ? 'S' : '-';
	perm[4] = (n & S_IRGRP) ? 'r' : '-';
	perm[5] = (n & S_IWGRP) ? 'w' : '-';
	if (n & S_IXGRP)
		perm[6] = (n & S_ISGID) ? 's' : 'x';
	else
		perm[6] = (n & S_ISGID) ? 'S' : '-';
	perm[7] = (n & S_IROTH) ? 'r' : '-';
	perm[8] = (n & S_IWOTH) ? 'w' : '-';
	if (n & S_IXOTH)
		perm[9] = (n & S_ISVTX) ? 't' : 'x';
	else
		perm[9] = (n & S_ISVTX) ? 'T' : '-';
	perm[10] = ' ';
	perm[11] = '\0';
	return (perm);
}

/*
**perm [10] '@'extended arthributes
*/

void	p_width(int w, char *name)
{
	int	l;

	l = ft_strlen(name);
	ft_printf(" %s", name);
	l = w - l + 1;
	while (l)
	{
		write(1, " ", 1);
		l--;
	}
}

void	p_nbrwidth(int w, int lnk)
{
	int	l;

	if (lnk == 0)
		l = w - 1;
	else
		l = w - ft_nbrlen(lnk);
	while (l > 0)
	{
		write(1, " ", 1);
		l--;
	}
	ft_printf("%d", lnk);
}

void	ls_fmt(t_lsflags *store, t_width *wid, t_node *tree)
{
	struct stat		sb;
	struct passwd	*p;
	struct group	*grp;
	char			*permission;

	lstat(tree->fullpath, &sb);
	permission = f_permission(sb.st_mode);
	if (store->l)
	{
		ft_printf("%s", permission);
		p_nbrwidth(wid->w_lnk, sb.st_nlink);
		p = getpwuid(sb.st_uid);
		p_width(wid->w_uid, p->pw_name);
		grp = getgrgid(sb.st_gid);
		p_width(wid->w_gid, grp->gr_name);
		ft_printf(" ");
		if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
			ft_printf("%3d, %3d", major(sb.st_rdev), minor(sb.st_rdev));
		else
			p_nbrwidth(wid->w_siz, sb.st_size);
		ft_printf(" %.6s ", ctime(&sb.st_mtime) + 4);
		ft_printf("%.5s ", ctime(&sb.st_mtime) + 11);
	}
	p_fname(store, permission[0], tree->fullpath);
	free(permission);
}
