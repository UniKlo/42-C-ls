/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/09/03 15:28:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		grab_flag(char *flags, t_lsflags *store)
{
	store->R == 1 || ft_strchr(flags, 'R') ? store->R = true : false;
	store->a == 1 || ft_strchr(flags, 'a') ? store->a = true : false; 
	store->t == 1 || ft_strchr(flags, 't') ? store->t = true : false;
	store->r == 1 || ft_strchr(flags, 'r') ? store->r = true : false;
	store->l == 1 || ft_strchr(flags, 'l') ? store->l = true : false;
}

int 	main(int argc, char **argv)
{
	int		i = 1;
	t_lsflags	store;

	argc = 0;
	while (argv[i] && argv[i][0] == '-')
	{
		grab_flag(++argv[i], &store); //get a set of flags
		i++;
	}
	printf("argv[%d] %s\n", i, argv[i]);
	store.pcurrent = true;
	while (argv[i]) //loop thru each path
	{
		if (argv[i][0] != '-')
		{
			store.pcurrent = false;
			operate(&store, argv[i]);
//			if (argv[i][strlen(argv[i])] != '/')
		}
		else
			printf("ls: %s: No such file or directory\n", argv[i]);//error messages
		i++;
	}
	printf("store.pcurrent: %d\n", store.pcurrent);
	if (store.pcurrent)
		operate(&store, "./");
	return (0);
}
