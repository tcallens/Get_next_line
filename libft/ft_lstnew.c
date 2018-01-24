/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:31:29 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/16 18:01:38 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, int content_size, int a)
{
	t_list *list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 100;
		list->fd = a;
	}
	else
	{
		list->content = NULL;
		list->content_size = content_size;
		list->fd = a;
	}
	list->next = NULL;
	return (list);
}
