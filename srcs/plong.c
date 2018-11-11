/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 01:46:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	fType(int n)
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

char	*fPermission(t_lsflags *store, int n)
{
	char	*perm;

	perm = ft_strnew(11);
	perm[0] = fType(n & S_IFMT);
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
	if (store->l)
		ft_printf("%s ", perm);
	return (perm);
}

/*
**perm [10] '@'extended arthributes
*/

void	ls_fmt(t_lsflags *store, t_node *tree)
{
	struct stat		sb;
	struct passwd	*p;
	struct group	*grp;
	char			*permission;

	permission = NULL;
	lstat(tree->fullpath, &sb);
	permission = fPermission(store, sb.st_mode);
	if (store->l)
	{
		ft_printf("%ld", (long)sb.st_nlink);
		ft_printf(" ");
		if ((p = getpwuid(sb.st_uid)) == NULL)
			perror("getpwuid() error\n");
		else
			ft_printf("%s  ", p->pw_name);
		if ((grp = getgrgid(sb.st_gid)) == NULL)
			perror("getgrgid() error\n");
		else
			ft_printf("%s", grp->gr_name);
		ft_printf(" ");
		if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
			ft_printf("%10d, %d", major(sb.st_rdev), minor(sb.st_rdev));
		else
			ft_printf("%8lld", (long long)sb.st_size);
		ft_printf(" ");
		ft_printf("%.6s ", ctime(&sb.st_mtime) + 4);
		ft_printf("%.5s ", ctime(&sb.st_mtime) + 11);
	}
	p_fname(permission[0], tree->fullpath);
	free(permission);
}

void	p_fname(char c, char *path)
{
	char	*fname;
	char	*color;
	ssize_t	ret;
	char	*bypath;

	bypath = NULL;
	if (c == 'd')
		color = BCYN;
	else if (c == 'l')
	{
		color = KMAG;
		ret = readlink(path, bypath, BUF_SIZE);
		ft_printf("readlink buff: %ld\n", ret);
		ft_printf("bypath: %s\n", bypath);
	}
	else if (c == 's')
		color = KGRN;
	else if (c == 'p')
		color = KYEL;
	else
		color = KNRM;
	if ((fname = ft_strrchr(path, '/')))
		ft_printf("%s%s\n%s", color, ++fname, KNRM);
	else
		ft_printf("%s%s\n", color, path, KNRM);
}
