/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/01 19:13:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lsLong(char *path)
{
	struct stat sb;
	struct passwd *p;
	struct group *grp;

//	ft_printf("I m here in lsLong.\n");
	ft_printf("WROKING on: %s\n", path);
	lstat(path, &sb);
/*--permission--*/
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c ",
			  (sb.st_mode & S_IFDIR) ? 'd' : '-',
//		   sb.st_mode & S_IFIFO ? 'p' : 0;
			  (sb.st_mode & S_IRUSR) ? 'r' : '-',
			  (sb.st_mode & S_IWUSR) ? 'w' : '-',
			  ((sb.st_mode & S_IXUSR) ? 'x' : '-'),
//			  ||
//			  ((sb.st_mode & S_ISUID) && (sb.st_mode & S_IXUSR) ? 's' : 'S' ),

			  (sb.st_mode & S_IRGRP) ? 'r' : '-',
			  (sb.st_mode & S_IWGRP) ? 'w' : '-',
			  (sb.st_mode & S_IXGRP) ? 'x' : '-',
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
	
/*--File Name--*/
	if ((path = ft_strrchr(path, '/')))
		ft_printf("%s\n", ++path);
	else
		ft_printf("%s\n", path);
}


