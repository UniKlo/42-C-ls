/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 03:12:04 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 03:27:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_node(t_lsflags *store, t_node *tree)
{
	if (!store->a && ft_strstr(tree->fullpath, "/."))
		return ;
	ls_fmt(store, tree);
}

void	print_sub(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_sub(store, tree->left);
		print_node(store, tree);
		if (tree->right)
			print_sub(store, tree->right);
	}
	else
	{
		if (tree->right)
			print_sub(store, tree->right);
		print_node(store, tree);
		if (tree->left)
			print_sub(store, tree->left);
	}
}

void	r_print(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			r_print(store, tree->left);
		if (!ft_strstr(tree->fullpath, "/."))
		{
			store->current = false;
			p_cmd(store, tree);
		}
		if (tree->right)
			r_print(store, tree->right);
	}
	else
	{
		if (tree->right)
			r_print(store, tree->right);
		if (!ft_strstr(tree->fullpath, "/."))
		{
			store->current = false;
			p_cmd(store, tree);
		}
		if (tree->left)
			r_print(store, tree->left);
	}
}

void	sub_sort(t_lsflags *store, t_ls *ls)
{
	t_node	*tree;
	int		a;

	tree = new_node(ls->sub[0]);
	a = 1;
	while (a < ls->si)
	{
		insert(store, tree, ls->sub[a]);
		a++;
	}
	print_sub(store, tree);
	if (store->R)
		r_print(store, tree);
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
}
