/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:41:52 by khou              #+#    #+#             */
/*   Updated: 2018/09/30 16:08:44 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		t_comp(struct timespec newt, struct timespec oldt)
{
	int		val;

	val = 0;
	if (newt.tv_sec == oldt.tv_sec)
	{
		if (newt.tv_nsec == oldt.tv_nsec)
		{
			//if (ft_strcmp(ename, tname) < 0)
			//	val = -1;
			//else
			//	val = 1;
			val = 0;
		}
		else if (newt.tv_nsec < oldt.tv_nsec)
			val = 1;
		else
			val = -1;
	}
	else if (newt.tv_sec < oldt.tv_sec)
		val = 1;
	else
		val = -1;
	return (val);
}

t_node	*newNode(struct stat *sb, char *fullpath) //??
{
    t_node   *node;
	node = (t_node*)malloc(sizeof(t_node));
    node->fullpath = fullpath;
	node->mtime = sb->st_mtimespec;//??
    node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*insert(t_node* node, char *fullpath, struct stat *sb)
{
    // If the tree is empty, return a new node
    if (node == NULL)
		return (newNode(sb, fullpath));
 
    // Otherwise, recur down the tree

    if (t_comp(sb->st_mtimespec, node->mtime) > 0)
        node->left = insert(node->left, fullpath, sb);
    else if (t_comp(sb->st_mtimespec, node->mtime) < 0)
        node->right = insert(node->right, fullpath, sb);
 
    // return the (unchanged) node pointer
    return (node);
}

void	sorting(t_lsflags *store, char *fullpath, struct stat *sb)
{
	static int		create_root = 1;
	static t_node	*root = NULL;
	bool	isDir;
	if (create_root)
	{
		insert(root, fullpath, sb);
		create_root = 0;
	}

	if (store->t)
	{
		ft_printf("sort by Mtime, path: %s\n", fullpath);
		ft_printf("sort by Mtime, mtime: %ld\n", (long) sb->st_mtime);
		ft_printf("sort by NANO Mtime, mtime: %ld\n", (long) sb->st_mtimespec.tv_nsec);
		ft_printf("whether it is a dir: %d\n",  sb->st_mode & S_IFDIR ? 1 : 0);
		isDir = sb->st_mode & S_IFDIR ? 1 : 0;
		insert(root, fullpath, sb);
	}
	else
		ft_printf("sort by ASCII, path: %s\n", fullpath);
}
/*
void	stage4sort(t_lsflags *store, char *path)
{

}
*/
