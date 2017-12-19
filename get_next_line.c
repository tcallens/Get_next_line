/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:24:03 by tcallens          #+#    #+#             */
/*   Updated: 2017/12/19 19:35:24 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_manage(t_list *list, int fd)
{
	while (list && list->fd != fd)
	{
		list = list->next;
	}
	if (!(list))
	{
		list = ft_lstnew(NULL, 0, fd);
	}
	return (list);
}

int		ft_findline(int fd, char *line)
{
	char	*buff;
	char *tmp;
	int	a;

	tmp = "";
	while ((buff = malloc(sizeof(char) * BUFF_SIZE))
			&& (a = read(fd, buff, BUFF_SIZE)
				&& tmp = malloc(sizeof(char) * BUFF_SIZE)))
	{
		if (a == -1)
			return (-1);
		tmp = ft_strjoin(tmp, buff);
		ft_strdel(buff);
	}
	return (0);

}

int		get_next_line(const int fd, char **line)
{
	static	t_list		*tl;
	t_list			*use;

	tl = NULL;
	line = NULL;
	use = ft_manage(tl, fd);
	return (1);
}
