/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/08/31 17:02:16 by khou             ###   ########.fr       */
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
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>


# include <stdbool.h>

/*
void	(*ft_printf)(const char *, ...);//pointers to function
# define ft_printf = &printf;
*/

/*
** ------------------------- Structure Definition ------------------------------
*/
typedef struct		s_ls
{
	char	*dir;
} t_ls;

typedef struct		s_lsflags
{
	bool	R;
	bool    l;
	bool    a;
	bool    t;
	bool    r;
	bool    pcurrent;
}	t_lsflags;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void	operate(t_lsflags *store, char *path);



#endif
