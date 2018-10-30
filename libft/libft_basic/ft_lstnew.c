/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:36:41 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:22 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = ft_memalloc(sizeof(t_list))) && content)
	{
		if ((lst->content = malloc(content_size)))
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
		else
			ft_memdel((void **)&lst);
	}
	return (lst);
}
