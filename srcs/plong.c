/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:45:49 by khou              #+#    #+#             */
/*   Updated: 2018/09/06 18:31:53 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	plong(char *readinto, struct stat *sb)
{
	struct passwd *p;
	struct group *grp;
	ft_printf("  name:                  %s\n", readinto);
	ft_printf("permission:              %c%c%c%c%c%c%c%c%c%c\n",
		   (sb->st_mode & S_IFDIR) ? 'd' : 0,
//		   sb->st_mode & S_IFIFO ? 'p' : 0;
		   (sb->st_mode & S_IRUSR) ? 'r' : '-',
		   (sb->st_mode & S_IWUSR) ? 'w' : '-',
		   (sb->st_mode & S_IXUSR) ? 'x' : '-' ||
		   ((sb->st_mode & S_ISUID) && (sb->st_mode & S_IXUSR) ? 's' : 'S' ),

		   (sb->st_mode & S_IRGRP) ? 'r' : '-',
		   (sb->st_mode & S_IWGRP) ? 'w' : '-',
		   (sb->st_mode & S_IXGRP) ? 'x' : '-',
		   (sb->st_mode & S_IROTH) ? 'r' : '-',
		   (sb->st_mode & S_IWOTH) ? 'w' : '-',
		   (sb->st_mode & S_IXOTH) ? 'x' : '-');
	ft_printf("Link count: %ld ", (long) sb->st_nlink);
	if ((p = getpwuid(sb->st_uid)) == NULL)
		perror("getpwuid() error");
	else
		ft_printf("pw_name: %s ",       p->pw_name);
	if ((grp = getgrgid(sb->st_gid)) == NULL)
		perror("getgrgid() error");
	else
		ft_printf("group: %s ", grp->gr_name);
	ft_printf("File size: %lld bytes\n",
		   (long long) sb->st_size);
	ft_printf("Last file modification:   %s", ctime(&sb->st_mtime));
}


