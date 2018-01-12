#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	int tg;
	int a;
	char	*line;

	fd = ac;
	tg = ac;
	a = 0;
	if ((((fd = open(av[1], O_RDONLY)) != -1) && (tg = open(av[2], O_RDONLY)) != -1))
	{
		get_next_line(fd, &line);
		ft_putstr(line);
		get_next_line(tg, &line);
		ft_putstr(line);
		get_next_line(fd, &line);
		ft_putstr(line);
		get_next_line(tg, &line);
		ft_putstr(line);
		get_next_line(fd, &line);
		ft_putstr(line);
		get_next_line(tg, &line);
		ft_putstr(line);
		get_next_line(fd, &line);
		ft_putstr(line);
		get_next_line(tg, &line);
		ft_putstr(line);
		get_next_line(fd, &line);
		ft_putstr(line);
	}
	else
		ft_putstr("bug dans main");
	close(fd);
	return (0);
}
