/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 03:12:04 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 20:56:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_node(t_lsflags *store, t_width *wid, t_node *tree)
{
	if (!store->a && ft_strstr(tree->fullpath, "/."))
		return ;
	ls_fmt(store, wid, tree);
}

void	print_sub(t_lsflags *store, t_width *wid, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_sub(store, wid, tree->left);
		print_node(store, wid, tree);
		if (tree->right)
			print_sub(store, wid, tree->right);
	}
	else
	{
		if (tree->right)
			print_sub(store, wid, tree->right);
		print_node(store, wid, tree);
		if (tree->left)
			print_sub(store, wid, tree->left);
	}
}

void	r_open(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			r_open(store, tree->left);
		if (!ft_strstr(tree->fullpath, "/."))
		{
			store->current = false;
			p_cmd(store, tree, NULL);
		}
		if (tree->right)
			r_open(store, tree->right);
	}
	else
	{
		if (tree->right)
			r_open(store, tree->right);
		if (!ft_strstr(tree->fullpath, "/."))
		{
			store->current = false;
			p_cmd(store, tree, NULL);
		}
		if (tree->left)
			r_open(store, tree->left);
	}
}

void	sub_sort(t_lsflags *store, t_ls *ls)
{
	t_node	*tree;
	int		a;
	t_width	wid;

	wid_init(&wid);
	tree = new_node(ls->sub[0], &wid);
	a = 1;
	while (a < ls->si)
	{
		insert(store, tree, ls->sub[a], &wid);
		a++;
	}
//	ft_printf("w_lnk: %d, w_uid: %d, w_gid: %d\n", wid.w_lnk, wid.w_uid, wid.w_gid);
	print_sub(store, &wid, tree);
	if (store->rec)
		r_open(store, tree);
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
}
