/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/10/30 23:42:05 by khou             ###   ########.fr       */
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
//	struct timespec	mtime;
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
	int			fi;
	char		*dir[125];
	int			di;
	char		*sub[125];
	int			si;
}			t_ls;

typedef int	(*ls_cmp)(const char *path1, const char *path2);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void	operate(t_lsflags *store, char *path);
void    plong(char *readinto, struct stat *sb);
void	f_or_d(t_ls *ls, char *path);
void	cmd_sort(t_lsflags *store, t_ls *ls);
t_node	*newNode(char *fullpath);
void	insert(t_lsflags *store, t_node *tree, char  *path);
void	openDir(t_lsflags *store, char *path);
void	print_tree(t_lsflags *store, t_node *tree);
ls_cmp	ls_dispatch(t_lsflags *store);
int		ls_timecmp(const char *path1, const char *path2);

#endif
