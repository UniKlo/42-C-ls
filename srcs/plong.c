/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/09 01:26:09 by khou             ###   ########.fr       */
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

char	*fPermission(int n)
{
	char	*perm = ft_strnew(11);

	perm[0] =  fType(n & S_IFMT);
	perm[1] = (n & S_IRUSR) ? 'r' : '-';
	perm[2] = (n & S_IWUSR) ? 'w' : '-';
	perm[3] = (n & S_IXUSR) ?
                  ((n & S_ISUID) ? 's' : 'x') :
                  ((n & S_ISUID) ? 'S' : '-');
	perm[4] = (n & S_IRGRP) ? 'r' : '-';
	perm[5] = (n & S_IWGRP) ? 'w' : '-';
	perm[6] = (n & S_IXGRP) ?
                  ((n & S_ISGID) ? 's' : 'x') :
                  ((n & S_ISGID) ? 'S' : '-');
	perm[7] = (n & S_IROTH) ? 'r' : '-';
	perm[8] = (n & S_IWOTH) ? 'w' : '-';	
	perm[9] = (n & S_IXOTH) ? ((n & S_ISVTX) ? 't': 'x') :
		((n & S_ISVTX) ? 'T': '-');
	perm[10] = ' ';//'@'extended arthributes 
	perm[11] = '\0';
	ft_printf("%s ", perm);
	return (perm);
}

void	ls_fmt( t_lsflags *store, t_node *tree)
{
	struct stat		sb;
	struct passwd	*p;
	struct group	*grp;
//	char			*fname;
	char	*permission = NULL;

//	ft_printf("                     WROKING on: %s\n", tree->fullpath);
	lstat(tree->fullpath, &sb);
	if (store->l)
	{
/*--permission--*/
		permission = fPermission(sb.st_mode);
		
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
		if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
			ft_printf("%10d, %d", major(sb.st_rdev), minor(sb.st_rdev));
		else
			ft_printf("%8lld", (long long) sb.st_size);
		ft_printf(" ");
/*--Mtime--*/
		ft_printf("%.6s ", ctime(&sb.st_mtime)+4);
		ft_printf("%.5s ", ctime(&sb.st_mtime)+11);
	
/*--File Name--*/
		pFname(permission[0], tree->fullpath);//how to mask
		free (permission);
	}
	else
		pFname(0, tree->fullpath);
}

# define BUF_SIZE 5000

void	pFname(char c, char *path)
{
	char	*fname;
	char	*color;
	ssize_t	ret;
	char	*bypath = NULL;
//	struct stat	sb;
	
	if (c == 'd')
		color = BCYN;
	else if (c == 'l')
	{
		color = KMAG;
		ret = readlink(path, bypath, BUF_SIZE);
//		bypath[ret] = '\0';
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

