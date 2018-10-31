/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/10/29 20:11:14 by khou             ###   ########.fr       */
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

int 	main(int argc, char **argv)
{
	int		i = 1;
	t_lsflags	store;
	t_ls	ls;
	
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
			f_or_d(&ls, argv[i]);
//			free(argv[i]);
		}
		else
			ft_printf("ls: %s: No such file or directory\n", argv[i]);//error messages
		i++;
	}
	ft_printf("store.pcurrent: %d\n", store.pcurrent);
	ft_printf("nub of files: %d\n", ls.fi); 
/* print out the list as it is
	int a = 0;
	while (a < ls.fi)
	{
		ft_printf("%s\n", ls.fil[a]);
		a++;
	}
*/
	cmd_sort(&ls);
	if (store.pcurrent)
		operate(&store, "./");
	return (0);
}
