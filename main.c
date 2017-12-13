#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	fd = ac;
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		ft_putendl("deuxieme");
		get_next_line(fd, &line);
		ft_putstr(line);
	}
	else
		ft_putstr("bug dans main");
	close(fd);
	return (0);
}
