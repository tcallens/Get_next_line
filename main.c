#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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
		ft_intendl(1);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(tg, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(tg, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(tg, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(tg, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
	/*	while (get_next_line(fd, &line) == 1)
		{
	//		a++;
	//		printf("%d", a);
	//		printf(": ");
	//		printf("ligne lue : %s\n", line);
	//		printf("------------------------\n");
			ft_putendl(line);
		}*/
	}
	else
		ft_putstr("bug dans main");
	close(fd);
	return (0);
}
