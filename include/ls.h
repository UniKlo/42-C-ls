/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/11/01 19:50:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# define LS_SIZE 5000
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
//	char			*name;
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
	bool    current;
}	t_lsflags;

typedef struct		s_ls
{
	char		*fil[LS_SIZE];
	int			fi;
	char		*dir[LS_SIZE];
	int			di;
	char		*sub[LS_SIZE];
	int			si;
}			t_ls;

typedef int	(*ls_cmp)(const char *path1, const char *path2);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void	operate(t_lsflags *store, char *path);
void    lsLong(char *readinto);
void	f_or_d(t_ls *ls, char *path);
void	cmd_sort(t_lsflags *store, t_ls *ls);
t_node	*newNode(char *fullpath);
void	insert(t_lsflags *store, t_node *tree, char  *path);
void	openDir(t_lsflags *store, char *path);
void	print_tree(t_lsflags *store, t_node *tree);
ls_cmp	ls_dispatch(t_lsflags *store);
int		ls_timecmp(const char *path1, const char *path2);
void    p_cmd(t_lsflags *store, t_node *tree);
void    ls_fmt(t_lsflags *store, t_node *tree);
 
#endif
