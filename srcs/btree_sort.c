/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:49:20 by khou              #+#    #+#             */
/*   Updated: 2018/11/09 23:16:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int     ls_timecmp(const char *path1, const char *path2)
{
    struct stat sb1;
    struct stat sb2;
    if (lstat(path1, &sb1) == -1)
        ft_printf("lstat- Could not open %s\n", path1);
    if (lstat(path2, &sb2) == -1)
        ft_printf("lstat- Could not open %s\n", path2);

    struct timespec t1 = sb1.st_mtimespec;
    struct timespec t2 = sb2.st_mtimespec;

    int     ret;

    ret = 0;
    if (t1.tv_sec == t2.tv_sec)
    {
        if (t1.tv_nsec == t2.tv_nsec)
        {
            if (ft_strcmp(path1, path2) > 0)
                ret = 1;
            else
                ret = -1;
        }
        else if (t1.tv_nsec < t2.tv_nsec)
            ret = 1;
        else
            ret = -1;
    }
    else if (t1.tv_sec < t2.tv_sec)
        ret = 1;
    else
        ret = -1;
    return (ret);
}

t_node  *newNode(char *fullpath)
{
    t_node   *node;
	struct stat sb;
    
    if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
    lstat(fullpath, &sb);
	if (S_ISDIR(sb.st_mode))
		node->isDir = true;
	else
		node->isDir = false;
	node->fullpath = ft_strdup(fullpath);
//	node->fullpath = fullpath;
	node->left = NULL;
	node->right = NULL;
//	ft_printf("Node: %s, isDir: %d\n", fullpath, node->isDir);
    return (node);
}

ls_cmp	ls_dispatch(t_lsflags *store)
{
 	ls_cmp f;
//	ft_printf("t: %d\n", store->t);
	if (store->t == 1)
		f = &ls_timecmp;
	else
		f = &ft_strcmp;
	return(f);
}

void    insert(t_lsflags *store, t_node *tree, char  *path)//no way have same name
{
	t_node *new;
	ls_cmp cmp;
	cmp = ls_dispatch(store);
	if (cmp(tree->fullpath, path) > 0)
	{
		if (!tree->left)
		{
			new = newNode(path);
			tree->left = new;
		}
		else
			insert(store, tree->left, path);
	}
	else
	{
		if (!tree->right)
		{
			new = newNode(path);
			tree->right = new;
		}
		else
			insert(store, tree->right, path);
	}
}
