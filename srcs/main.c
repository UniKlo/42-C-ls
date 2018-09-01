/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/08/31 14:38:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		grab_flag(char *flags, t_lsflags *store)
{
/*
	while (*flags)
	{
		printf("flag: %s\n", flags);
		*flags++ == 'R'? store.R = 1 : 0;
	}
doesnt work bc *flags is on stack, no \0 in the end
*/
	store->R == 1 || ft_strchr(flags, 'R') ? store->R = true : false;
	store->a == 1 || ft_strchr(flags, 'a') ? store->a = true : false;
	store->t == 1 || ft_strchr(flags, 't') ? store->t = true : false;
	store->r == 1 || ft_strchr(flags, 'r') ? store->r = true : false;
	store->l == 1 || ft_strchr(flags, 'l') ? store->l = true : false;
}
/*
void		grab_path(char *path)
{
	static int		i = 0;
	static char		*dir[10];
//maybe dont need to store dir
//after getting all the flags, apply to each dir seperatly 
	
	dir[i] = path;
	printf("file: %s, open %d times\n", dir[i], i + 1);
//	ft_ls(dir[i]);
	i++;
//	printf("file: %s, open %d times\n", path, i);
}
*/

int 	main(int argc, char **argv)
{
	int		i = 0;
	t_lsflags	store;

	argc = 0;
	while (argv[++i] && argv[i][0] == '-')
		grab_flag(++argv[i], &store); //get a set of flags
//	printf("argv: %s\n", argv[i]);
	store.pcurrent = true;
	while (argv[i])
	{
		if (argv[i][0] != '-')
		{
			store.pcurrent = false;
			operate(&store, argv[i]);
		}
		else
			printf("ls: %s: No such file or directory\n", argv[i]);
//  error messages
		i++;
	}
	if (store.pcurrent)
		operate(&store, ".");
	return (0);
}
