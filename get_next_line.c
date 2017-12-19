#include "get_next_line.h"

t_list		*ft_manage(t_list **list, int fd)
{
	while (*list && (*list)->fd != fd)
	{
		list = (*list)->next;
	}
	if (!(*list))
	{
		*list = ft_lstnew(NULL, 0, fd);
	}
	return (*list);
}

int		*ft_findline(int fd, char *line)
{
	char	*buff;
	int	a;

	while ((buff = malloc(sizeof(char) * BUFF_SIZE))
			&& (a = read(fd, buff, BUFF_SIZE)))
	{
		if (a = -1)
			return (-1);

	}

}

int		get_next_line(const int fd, char **line)
{
	static	t_list		*tl;
	t_list			*use;
	char		*buf;
	int		a;

	tl = NULL;
	use = ft_manage(tl, fd);
	return (1);
}
