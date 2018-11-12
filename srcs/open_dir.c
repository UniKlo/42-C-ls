/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 20:34:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	max_wid(struct stat sb, t_width *wid)
{
	struct passwd	*p;
	struct group	*grp;
	int				l;

	l = ft_nbrlen((int)sb.st_nlink);
	if (wid->w_lnk < l)
		wid->w_lnk = l;
	if ((p = getpwuid(sb.st_uid)) == NULL)
		perror("getpwuid() error\n");
	else
		l = ft_strlen(p->pw_name);
		if (wid->w_uid < l)
			wid->w_uid = l;
	if ((grp = getgrgid(sb.st_gid)) == NULL)
		perror("getgrgid() error\n");
	else
		l = ft_strlen(grp->gr_name);
		if (wid->w_gid < l)
			wid->w_gid = l;
}

void	p_dirsize(t_lsflags *store, t_ls *ls, int blksize)
{
	if (store->l)
	{
		if (store->a)
			ft_printf("total %d\n", blksize);
		else if (!store->a && ls->si > 2)
			ft_printf("total %d\n", blksize);
	}
}

//void	read_dir(DIR *dr, t_lsflags *store, t_ls *ls, t_width *wid, char *path)
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
			// max_wid(sb, wid);//?
		}
		ls->si++;
	}
	p_dirsize(store, ls, blksize);
}

void	open_dir(t_lsflags *store, char *path)
{
	t_ls			ls;
	DIR				*dr;
	char			*fname;
	int				b;
//	t_width			wid;

	dr = opendir(path);
	if (dr == NULL)
	{
		if ((fname = ft_strrchr(path, '/')))
			ft_printf("ls: %s: Permission denied\n", ++fname);
		return ;
	}
	ls_init(&ls);
//	wid_init(&wid);
	//read_dir(dr, store, &ls, &wid, path);
	read_dir(dr, store, &ls, path);
	b = 0;
	sub_sort(store, &ls);//?
	
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
