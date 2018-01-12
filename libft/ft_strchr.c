/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:54:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/12 17:34:30 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	char *tmp;

	if (!(str))
		return (NULL);
	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == c)
		{
			tmp++;
			return (tmp);
		}
		tmp++;
	}
	if (*tmp == c)
	{
		tmp++;
		return (tmp);
	}
	return (NULL);
}
