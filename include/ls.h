/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/10/28 03:40:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/include/libft.h"
# include "../libft/include/printf.h"
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
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_node
{
	char			*fullpath;
	bool			isDir;
	struct timespec	mtime;
	struct s_node 	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_lsflags
{
	bool	R;
	bool    a;
	bool    t;
	bool    r;
	bool    l;
	bool    pcurrent;
}	t_lsflags;

typedef struct		s_ls
{
	char		*fil[125];
	int		fi;
	char		*dir[125];
	int		di;
}			t_ls;



/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void	operate(t_lsflags *store, char *path);
void    plong(char *readinto, struct stat *sb);
//void    sorting(t_lsflags *store, char *path, struct stat *sb);
void	f_or_d(t_ls *ls, char *path);
void	cmd_sort(t_ls *ls);
#endif
