/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:14:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/27 13:18:59 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_lstrlen(wchar_t *ls)
{
	int len;

	len = 0;
	while (*ls != L'\0')
	{
		if (*ls <= 0x007F)
			len += 1;
		else if (*ls <= 0x07FF)
			len += 2;
		else if (*ls <= 0xFFFF)
			len += 3;
		else if (*ls <= 0x10FFFF)
			len += 4;
		ls++;
	}
	return (len);
}
