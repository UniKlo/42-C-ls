/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:12:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/10 23:13:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
# include <wchar.h>

/*
** ---------------------------- COLOR MACROS -----------------------------------
*/

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define BBLK  "\033[1m\033[30m"
# define BRED  "\033[1m\033[31m"
# define BGRN  "\033[1m\033[32m"
# define BYEL  "\033[1m\033[33m"
# define BBLU  "\033[1m\033[34m"
# define BMAG  "\033[1m\033[35m"
# define BCYN  "\033[1m\033[36m"
# define BWHT  "\033[1m\033[37m"

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	s_print
{
	char		*format;
	va_list		ap;
	int			ret;
	int			fd;

}				t_print;

typedef struct	s_block
{
	bool		hash;
	bool		left_align;
	bool		pad_s;
	bool		pad_z;
	bool		sign;
	int			width;
	int			p_dot;
	char		length[3];
	char		specifier;
	int			len;
	va_list		*ap;
	int			*ret;
	int			*fd;
	intmax_t	s_data;
	uintmax_t	un_data;
	bool		p_mark;
}				t_block;

typedef void	(*t_fun_tbl)(t_block *blk);

typedef struct	s_write
{
	char		sign;
	uintmax_t	nbr;
	int			length;
	int			space;
	int			zero;
	int			base;
}				t_write;
/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void			establish(t_print *all, t_block *blk);
void			grab_flag(t_block *blk, char *format, int *i);
int				width(t_block *blk, char *blk_fmt);
int				p_dot(t_block *blk, char *blk_fmt);
int				is_flag(t_block *blk, char c);
void			valid_all(t_block *blk);
int				specifier(t_block *blk, char c);
t_fun_tbl		dispatch_table(char c);
void			p_diuox(t_block *blk);
void			p_c(t_block *blk);
void			set_s(t_block *blk);
void			set_ls(t_block *blk);
int				bigger(int a, int b);
void			establish_write(t_write *act);
void			undef(t_block *blk);
int				ft_printf(const char *format, ...);
int				length(t_block *blk, char *blk_fmt);
void			signed_lengh(t_block *blk, t_write *act);
void			unsigned_lengh(t_block *blk, t_write *act);

#endif
