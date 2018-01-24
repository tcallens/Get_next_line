/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:24:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/19 06:48:58 by tcallens         ###   ########.fr       */
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
	tmp = ft_lstnew(NULL, 100, fd);
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
	while (line[a] && line[a] != '\n')
		a++;
	end = (char *)malloc(sizeof(char) * (a + 1));
	a = 0;
	while(line[a] && line[a] != '\n')
	{
		end[a] = line[a];
		a++;
	}
	end[a] = '\0';
	return(end);
}

static int	ft_findline(int fd, t_list *list, char **tmp, char *buff)
{
	if ((ft_strchr(list->content, '\n') == NULL))
	{
		if (list->content && list->content_size > 0)
			*tmp = list->content;
		list->content = NULL;
		while (((list->content_size = read(fd, buff, BUFF_SIZE)) > 0) 
				&& (ft_strchr(buff, '\n') == NULL))
		{
			buff[list->content_size] = '\0';
			*tmp = ft_strjoin(*tmp, buff);
		}
		if (list->content_size == -1)
			return (-1);
		if (list->content_size > 0)
			*tmp = ft_strjoin(*tmp, ft_linespace(buff));
		if (list->content_size > 0 && ft_strchr(buff, '\n') != NULL)
			list->content = (void *)(ft_strchr(buff, '\n'));
	}	
	else
	{
		*tmp = ft_linespace((char *)list->content);
		list->content = (void *)ft_strchr((char *)list->content, '\n');
	}
	return(1);
}


int		get_next_line(const int fd, char **line)
{
	static	t_list			*tl = NULL;
	t_list				*use;
	int				num;
	char				*buff;
	char				*tmp;

	tmp = "\0";
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!line || BUFF_SIZE < 0 || fd < 0)
		return (-1);
	use = ft_manage(&tl, fd);
	num = ft_findline(use->fd, use, &tmp, buff);
	if ((use->content_size == 0) && (ft_strchr(use->content, '\n') == NULL) && (!ft_strlen(tmp)))
	{
		return (0);
	}
	*line = tmp;
	return (num);
}
