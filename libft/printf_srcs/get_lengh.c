/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lengh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:01:18 by khou              #+#    #+#             */
/*   Updated: 2018/09/27 11:07:19 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		length(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	if (blk_fmt[x] == 'h' && blk_fmt[x + 1] == 'h' && (x = x + 2))
		ft_strcpy(blk->length, "hh\0");
	else if (*blk->length != 'z' && blk_fmt[x] == 'h' && (x = x + 1))
		ft_strcpy(blk->length, "h\0");
	else if (blk_fmt[x] == 'l' && blk_fmt[x + 1] == 'l' && (x = x + 2))
		ft_strcpy(blk->length, "ll\0");
	else if (blk_fmt[x] == 'l' && (x = x + 1))
		ft_strcpy(blk->length, "l\0");
	else if (blk_fmt[x] == 'z' && (x = x + 1))
		ft_strcpy(blk->length, "z\0");
	else if (blk_fmt[x] == 'j' && (x = x + 1))
		ft_strcpy(blk->length, "j\0");
	return (x - 1);
}

void	signed_lengh(t_block *blk, t_write *act)
{
	act->sign = '+';
	if (blk->length[0] == '\0')
		blk->s_data = (int)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'h' && blk->length[1] == 'h')
		blk->s_data = (char)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'h')
		blk->s_data = (short int)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'l' && blk->length[1] == 'l')
		blk->s_data = va_arg(*blk->ap, long long int);
	else if (blk->length[0] == 'l')
		blk->s_data = va_arg(*blk->ap, long int);
	else if (blk->length[0] == 'j')
		blk->s_data = va_arg(*blk->ap, intmax_t);
	else if (blk->length[0] == 'z')
		blk->s_data = va_arg(*blk->ap, size_t);
	if (blk->s_data < 0)
	{
		act->sign = '-';
		act->nbr = -blk->s_data;
	}
	else
		act->nbr = blk->s_data;
	(!(blk->sign) && blk->s_data >= 0) ? act->sign = '\0' : 0;
}

void	unsigned_lengh(t_block *blk, t_write *act)
{
	act->sign = '+';
	if (blk->length[0] == '\0')
		blk->un_data = (unsigned int)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'h' && blk->length[1] == 'h')
		blk->un_data = (unsigned char)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'h')
		blk->un_data =\
			(unsigned short int)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'l' && blk->length[1] == 'l')
		blk->un_data = va_arg(*blk->ap, unsigned long long int);
	else if (blk->length[0] == 'l')
		blk->un_data = va_arg(*blk->ap, unsigned long int);
	else if (blk->length[0] == 'j')
		blk->un_data = va_arg(*blk->ap, uintmax_t);
	else if (blk->length[0] == 'z')
		blk->un_data = va_arg(*blk->ap, size_t);
	act->nbr = blk->un_data;
	!(blk->sign) ? act->sign = '\0' : 0;
}
