/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:34:02 by khou              #+#    #+#             */
/*   Updated: 2018/07/30 19:02:00 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		clean;
	char	*ret;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	clean = ft_strlen(s);
	while (clean > 0 && ft_isspace(s[clean - 1]))
		clean--;
	ret = ft_strnew(clean);
	if (ret)
	{
		ft_strncpy(ret, s, clean);
		ret[clean] = 0;
	}
	return (ret);
}
