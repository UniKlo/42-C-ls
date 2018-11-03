/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/02 16:37:16 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	fType(int n)
{
	char c;

	c = '\0';
	if (n == S_IFLNK)
		c = 'l';
	else if (n & S_IFREG) // how to mask it out?
		c = '-';
	else if (n & S_IFDIR)
		c = 'd';
    else if (n & S_IFCHR)
        c = 'c';
	else if (n & S_IFBLK)
        c = 'b';
	else if (n & S_IFIFO)
        c = 'p';
	else
		c = '?';
	return (c);
}

void	ls_fmt( t_lsflags *store, t_node *tree)
{
	struct stat		sb;
	struct passwd	*p;
	struct group	*grp;
//	char			*fname;

//	ft_printf("                     WROKING on: %s\n", tree->fullpath);
	lstat(tree->fullpath, &sb);
	if (store->l)
	{
/*--permission--*/
		ft_printf("%c%c%c%c%c%c%c%c%c%c%c ",
				  fType(sb.st_mode & S_IFMT),//how to mask
				  (sb.st_mode & S_IRUSR) ? 'r' : '-',
				  (sb.st_mode & S_IWUSR) ? 'w' : '-',
				  (sb.st_mode & S_IXUSR) ?
				  ((sb.st_mode & S_ISUID) ? 's' : 'x') :
				  ((sb.st_mode & S_ISUID) ?	'S' : '-'),
				  (sb.st_mode & S_IRGRP) ? 'r' : '-',
				  (sb.st_mode & S_IWGRP) ? 'w' : '-',
				  (sb.st_mode & S_IXGRP) ?
				  ((sb.st_mode & S_ISGID) ?	's' : 'x') :
				  ((sb.st_mode & S_ISGID) ? 'S' : '-'),
				  (sb.st_mode & S_IROTH) ? 'r' : '-',
				  (sb.st_mode & S_IWOTH) ? 'w' : '-',
				  (sb.st_mode & S_IXOTH) ? 'x' : '-',
				  '@'
			);
/*--Link count--*/
		ft_printf("%ld", (long) sb.st_nlink);
		ft_printf(" ");
/*--UID--*/
		if ((p = getpwuid(sb.st_uid)) == NULL)
			perror("getpwuid() error\n");
		else
			ft_printf("%s  ", p->pw_name);
/*--GID--*/
		if ((grp = getgrgid(sb.st_gid)) == NULL)
			perror("getgrgid() error\n");
		else
			ft_printf("%s", grp->gr_name);
		ft_printf(" ");
/*--File Size--*/
		ft_printf("%8lld", (long long) sb.st_size);
		ft_printf(" ");
/*--Mtime--*/
		ft_printf("%.6s ", ctime(&sb.st_mtime)+4);
		ft_printf("%.5s ", ctime(&sb.st_mtime)+11);
	}
/*--File Name--*/
	pFname(fType(sb.st_mode & S_IFMT), tree->fullpath);//how to mask
}

void	pFname(char c, char *path)
{
	char	*fname;
	char	*color;
	char	*bypath = NULL;
//	struct stat	sb;
	
	if (c == 'd')
		color = BCYN;
	else if (c == 'l')
	{
		color = KMAG;
		readlink(path, bypath, 5000);
		ft_printf("bypath: %s\n", bypath);
	}
	else
		color = KNRM;

	if ((fname = ft_strrchr(path, '/')))
        ft_printf("%s%s\n%s", color, ++fname, KNRM);
    else
        ft_printf("%s%s\n", color, path, KNRM);
}

