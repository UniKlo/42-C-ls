/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:11:25 by khou              #+#    #+#             */
/*   Updated: 2018/11/13 01:58:36 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	p_cmd(t_lsflags *store, t_node *tree, t_width *wid)
{
	if (!tree->is_dir)
	{
		if (store->rec)
			return ;
		ls_fmt(store, wid, tree);
	}
	if (tree->is_dir)
	{
		if (!store->current)
			ft_printf("\n%s:\n", tree->fullpath);
		open_dir(store, tree->fullpath);
	}
}

void	print_tree(t_lsflags *store, t_node *tree, t_width *wid)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_tree(store, tree->left, wid);
		p_cmd(store, tree, wid);
		if (tree->right)
			print_tree(store, tree->right, wid);
	}
	else
	{
		if (tree->right)
			print_tree(store, tree->right, wid);
		p_cmd(store, tree, wid);
		if (tree->left)
			print_tree(store, tree->left, wid);
	}
}

void	f_sort(t_lsflags *store, t_ls *ls)
{
	t_node	*tree;
	int		a;
	t_width wid;

	wid_init(&wid);
	tree = new_node(ls->fil[0], &wid);
	a = 1;
	while (a < ls->fi)
	{
		insert(store, tree, ls->fil[a], &wid);
		a++;
	}
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
	print_tree(store, tree, &wid);
}

void	d_sort(t_lsflags *store, t_ls *ls)
{
	t_node	*tree;
	int		a;
	t_width	wid;

	wid_init(&wid);
	tree = new_node(ls->dir[0], &wid);
	a = 1;
	while (a < ls->di)
	{
		insert(store, tree, ls->dir[a], &wid);
		a++;
	}
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
	print_tree(store, tree, &wid);
}

void	cmd_sort(t_lsflags *store, t_ls *ls)
{
	if (ls->fi != 0)
		f_sort(store, ls);
	if (ls->di != 0)
	{
		if (ls->fi != 0)
			ft_printf("\n");
		d_sort(store, ls);
	}
}
