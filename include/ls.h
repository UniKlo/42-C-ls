/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/09/05 00:12:54 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdbool.h>
# include <time.h>

/*
void	(*ft_printf)(const char *, ...);//pointers to function
# define ft_printf = &printf;
*/

/*
** ------------------------- Structure Definition ------------------------------
*/
/*
typedef struct		s_node
{
	char			*fullpath;
	timespec		mtime;
	struct t_node 	left;
	struct t_node	right;
} t_node;
*/
typedef struct		s_lsflags
{
	bool	R;
	bool    a;
	bool    t;
	bool    r;
	bool    l;
	bool    pcurrent;
}	t_lsflags;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void	operate(t_lsflags *store, char *path);
void    plong(char *readinto, struct stat *sb);
void    sorting(t_lsflags *store, char *path, struct stat *sb);

#endif
