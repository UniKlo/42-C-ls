/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:49:20 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 01:44:10 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ls_timecmp(const char *path1, const char *path2)
{
	struct stat		sb1;
	struct stat		sb2;
	int				ret;

	lstat(path1, &sb1) && lstat(path2, &sb2);
	ret = 0;
	if (sb1.st_mtimespec.tv_sec == sb2.st_mtimespec.tv_sec)
	{
		if (sb1.st_mtimespec.tv_nsec == sb2.st_mtimespec.tv_nsec)
		{
			if (ft_strcmp(path1, path2) > 0)
				ret = 1;
			else
				ret = -1;
		}
		else if (sb1.st_mtimespec.tv_nsec < sb2.st_mtimespec.tv_nsec)
			ret = 1;
		else
			ret = -1;
	}
	else if (sb1.st_mtimespec.tv_sec < sb2.st_mtimespec.tv_sec)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

t_node	*new_node(char *fullpath)
{
	t_node		*node;
	struct stat sb;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	lstat(fullpath, &sb);
	if (S_ISDIR(sb.st_mode))
		node->is_dir = true;
	else
		node->is_dir = false;
	node->fullpath = ft_strdup(fullpath);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

ls_cmp	ls_dispatch(t_lsflags *store)
{
	ls_cmp	f;

	if (store->t == 1)
		f = &ls_timecmp;
	else
		f = &ft_strcmp;
	return (f);
}

void	insert(t_lsflags *store, t_node *tree, char *path)
{
	t_node	*new;
	ls_cmp	cmp;

	cmp = ls_dispatch(store);
	if (cmp(tree->fullpath, path) > 0)
	{
		if (!tree->left)
		{
			new = new_node(path);
			tree->left = new;
		}
		else
			insert(store, tree->left, path);
	}
	else
	{
		if (!tree->right)
		{
			new = new_node(path);
			tree->right = new;
		}
		else
			insert(store, tree->right, path);
	}
}
