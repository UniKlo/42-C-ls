/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:59:53 by khou              #+#    #+#             */
/*   Updated: 2018/11/13 01:21:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# define LS_SIZE 5000
# define BUF_SIZE 5000

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
	bool			is_dir;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_lsflags
{
	bool			R;
	bool			a;
	bool			t;
	bool			r;
	bool			l;
	bool			current;
}					t_lsflags;

typedef struct		s_ls
{
	char			*fil[LS_SIZE];
	int				fi;
	char			*dir[LS_SIZE];
	int				di;
	char			*sub[LS_SIZE];
	int				si;
}					t_ls;

typedef struct		s_width
{
	int				w_lnk;
	int				w_uid;
	int				w_gid;
	int				w_siz;		
}					t_width;

typedef struct		s_free
{
	t_node			*root[LS_SIZE];
	int				ri;
}					t_free;

t_free g_free;

typedef int	(*ls_cmp)(const char *path1, const char *path2);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void				operate(t_lsflags *store, char *path);
void				ls_init(t_ls *ls);
void				flag_init(t_lsflags *store);
void				wid_init(t_width *wid);
void				cmd_sort(t_lsflags *store, t_ls *ls);
void				sub_sort(t_lsflags *store, t_ls *ls);
void    max_wid(struct stat sb, t_width *wid);
t_node				*new_node(char *fullpath, t_width *wid);
void				insert(t_lsflags *store, t_node *tree, char *path, t_width *wid);
void				open_dir(t_lsflags *store, char *path);
void				print_tree(t_lsflags *store, t_node *tree, t_width *wid);
ls_cmp				ls_dispatch(t_lsflags *store);
int					ls_timecmp(const char *path1, const char *path2);
void				p_cmd(t_lsflags *store, t_node *tree, t_width *wid);
void				ls_fmt(t_lsflags *store, t_width *wid, t_node *tree);
void				p_fname(t_lsflags *store, char c, char *path);
void				free_tree(t_node *tree);
#endif
