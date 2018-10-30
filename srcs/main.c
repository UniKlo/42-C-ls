/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/10/28 03:47:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		ls_grab_flag(char *flags, t_lsflags *store)
{
	store->R == 1 || ft_strchr(flags, 'R') ? store->R = true : false;
	store->a == 1 || ft_strchr(flags, 'a') ? store->a = true : false; 
	store->t == 1 || ft_strchr(flags, 't') ? store->t = true : false;
	store->r == 1 || ft_strchr(flags, 'r') ? store->r = true : false;
	store->l == 1 || ft_strchr(flags, 'l') ? store->l = true : false;
}

void	ls_init(t_ls *ls)
{
	ls->fi = 0;
	ls->di = 0;
}

t_node  *newNode(struct stat *sb, char *fullpath) //??
{
    t_node   *node;

	sb = 0;
    node = (t_node*)malloc(sizeof(t_node));
    node->fullpath = fullpath;
	//   node->mtime = sb->st_mtimespec;//??
    node->left = NULL;
    node->right = NULL;
    return (node);
}


//add function pointer argument for comparison
void    insert(t_node *tree, char  *path)
{
	t_node *new;
	
	if (ft_strcmp(tree->fullpath, path) > 0)
	{
		if (!tree->left)
		{
			new = newNode(0, path);
			tree->left = new;
		}
		else
			insert(tree->left, path);
	}
	else if (ft_strcmp(tree->fullpath, path) < 0)
	{
		if (!tree->right)
		{
			new = newNode(0, path);
			tree->right = new;
		}
		else
			insert(tree->right, path);
	}
	else //file has equal name (error?)
		;
}

//remove printf
void    print_tree(t_node *tree)
{
	if (tree->left)
		print_tree(tree->left);
	printf("%s\n", tree->fullpath);
	if (tree->right)
		print_tree(tree->right);
}

int 	main(int argc, char **argv)
{
	int		i = 1;
	t_lsflags	store;
	t_ls	ls;
	
//	char		*tmp;

	argc = 0;
	while (argv[i] && argv[i][0] == '-')
	{
		ls_grab_flag(++argv[i], &store); //get a set of flags
		i++;
	}
	ft_printf("argv[%d] %s\n", i, argv[i]);
	store.pcurrent = true;
	ls_init(&ls);
	while (argv[i]) //loop thru cmd add
	{
		if (argv[i][0] != '-')
		{
			store.pcurrent = false;
//			if (argv[i][strlen(argv[i-1])] != '/')
//				argv[i] = ft_strjoin(argv[i], "/");

//			operate(&store, argv[i]); //send out path name
			f_or_d(&ls, argv[i]);
//			free(argv[i]);
		}
		else
			ft_printf("ls: %s: No such file or directory\n", argv[i]);//error messages
		i++;
	}
	ft_printf("store.pcurrent: %d\n", store.pcurrent);
	ft_printf("nub of files: %d\n", ls.fi); 
/*
	int a = 0;
	while (a < ls.fi)
	{
		ft_printf("%s\n", ls.fil[a]);
		a++;
	}
*/
	t_node *tree = newNode(0, ls.fil[0]);
//	tree->fullpath = ls.fil[0];
    int a = 1;
    while (a < ls.fi)
    {
        insert(tree ,ls.fil[a]);
        a++;
    }	
	print_tree(tree);
	if (store.pcurrent)
		operate(&store, "./");
	return (0);
}
