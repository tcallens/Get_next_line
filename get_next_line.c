/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:24:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/12 18:25:47 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*ft_manage(t_list **list, int fd)
{
	t_list *tmp;
	t_list *pre;

	tmp = *list;
	pre = NULL;
	while (tmp && tmp->fd != fd)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		return (tmp);
	tmp = ft_lstnew(NULL, 0, fd);
	if (*list)
		pre->next = tmp;
	else
		*list = tmp;
	return (tmp);
}

static char		*ft_linespace(char *line)
{
	int 	a;
	char	*end;

	a = 0;
	while (line[a] != '\n')
		a++;
	end = (char *)malloc(sizeof(char) * (a + 2));
	a = 0;
	while(line[a] != '\n')
	{
		end[a] = line[a];
		a++;
	}
	end[a++] = '\n';
	a++;
	end[a] = '\0';
	return(end);
}

static int	ft_findline(int fd, t_list *list, char *buff, char **tmp)
{
	int		br;

	if ((ft_strchr(list->content, '\n') == NULL))
	{
		if (list->content)
			*tmp = list->content;
		while (((br = read(fd, buff, BUFF_SIZE)) > 0) 
				&& (ft_strchr(buff, '\n') == NULL))
			*tmp = ft_strjoin(*tmp, buff);
		if (br == -1)
			return (-1);
		if (br == 0 && !(list->content))
			return (0);
		*tmp = ft_strjoin(*tmp, ft_linespace(buff));
		list->content = (void *)(ft_strchr(buff, '\n'));
	}
	else
	{
		*tmp = ft_linespace((char *)list->content);
		list->content = ft_strchr(list->content, '\n');
	}
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list		*tl;
	t_list				*use;
	char			*buff;
	char			*tmp;
	int			num;

	if (!line || BUFF_SIZE < 0)
		return (-1);
	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	use = ft_manage(&tl, fd);
	num = ft_findline(use->fd, use, buff, &tmp);
	if (num == 1)
	{
		*line = tmp;
		return (1);
	}
	else
		return (num);
}
