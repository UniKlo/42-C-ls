/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:46:43 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:20 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_store_word(const char *str, int i, char **ret, char c)
{
	int		len;
	int		skip;

	skip = 0;
	len = 0;
	while (*str == c)
	{
		str++;
		skip++;
	}
	while (str[len] && str[len] != c)
		len++;
	if (len > 0)
	{
		ret[i] = ft_strnew(len);
		ft_strncpy(ret[i], str, len);
	}
	return (skip + len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**ret;
	int		i;
	int		nw;

	if (!s)
		return (NULL);
	nw = ft_count_nbr_block(s, c);
	ret = (char **)ft_memalloc((nw + 1) * sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_store_word(s, i++, ret, c);
		s += len;
	}
	ret[nw] = 0;
	return (ret);
}
