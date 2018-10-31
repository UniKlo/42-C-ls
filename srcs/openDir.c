/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openDir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/10/30 23:54:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sub_init(t_ls *ls)
{
	ls->si = 0;
}

void	s_sort(t_lsflags *store, t_ls *ls)
{
	t_node *tree = newNode(ls->sub[0]);
    int a = 1;
    while (a < ls->si)
    {
//      ft_printf("insert: %s\n", ls->fil[a]);
        insert(store, tree ,ls->sub[a]);
        a++;
    }
    print_tree(store, tree);
}

void	openDir(t_lsflags *store, char *path)
{
	t_ls			ls;
	DIR				*dr = opendir(path);
	struct dirent	*file;
	if (dr == NULL)
		ft_printf("%s is not readable.\n", path);
	sub_init(&ls);
	while ((file = readdir(dr)))
	{
		ft_printf("%s\n", file->d_name);
//		ls.sub[ls.si++] = file->d_name;
	}
	closedir(dr);
	store = NULL;
//	s_sort(store, &ls);
}
