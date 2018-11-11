/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 02:46:28 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_dir(DIR *dr, t_lsflags *store, t_ls *ls, char *path)
{
	struct dirent	*file;
	char			*tmp;
	int				blksize;
	struct stat		sb;

	blksize = 0;
	while ((file = readdir(dr)))
	{
		tmp = ft_strjoin(path, "/");
		ls->sub[ls->si] = ft_strjoin(tmp, file->d_name);
		free(tmp);
		if (store->l)
		{
			if (!store->a && ft_strstr(ls->sub[ls->si], "/."))
				;
			else
				lstat(ls->sub[ls->si], &sb);
			blksize += sb.st_blocks;
		}
		ls->si++;
	}
//	ft_printf("si: %d\n", ls->si);
	if (store->l)
	{
		if (store->a)
			ft_printf("total %d\n", blksize);
		else if (!store->a && ls->si > 2)
			ft_printf("total %d\n", blksize);
	}
}

void	open_dir(t_lsflags *store, char *path)
{
	t_ls			ls;
	DIR				*dr;
	char			*fname;
	int				b;

	dr = opendir(path);
	if (dr == NULL)
	{
		if ((fname = ft_strrchr(path, '/')))
			ft_printf("ls: %s: Permission denied\n", ++fname);
		return ;
	}
	ls_init(&ls);
	read_dir(dr, store, &ls, path);
	b = 0;
	sub_sort(store, &ls);
	while (b < ls.si)
	{
		free(ls.sub[b]);
		b++;
	}
	closedir(dr);
}
/*
**1.open dir and put all files into an array.
**2. and it will be sorted as a tree in sub_sort.
**3. free strjoin and the tree.
**4. close dir.
*/
