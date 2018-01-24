#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	int tg;
	int ok;
	int a;
	char	*line;

	fd = ac;
	tg = ac;
	ok = ac;
	a = 0;
	line = "";
	if ((((fd = open(av[1], O_RDONLY)) != -1) && (tg = open(av[2], O_RDONLY)) != -1) && (ok = open(av[3], O_RDONLY)) != -1)
	{
	/*	ft_intendl(get_next_line(fd, &line));
		ft_putendl(line);
		ft_intendl(get_next_line(tg, &line));
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
		ft_putendl(line);*/
		while (get_next_line(fd, &line) == 1)
		{
	//		a++;
	//		printf("%d", a);
	//		printf(": ");
	//		printf("ligne lue : %s\n", line);
	//		printf("------------------------\n");
			ft_putendl(line);
		}	
		ft_putendl("*-*-*-*-*-*-*-*-*-*-*");
		while (get_next_line(tg, &line) == 1)
		{
	//		a++;
	//		printf("%d", a);
	//		printf(": ");
	//		printf("ligne lue : %s\n", line);
	//		printf("------------------------\n");
			ft_putendl(line);
		}	
		ft_putendl("*-*-*-*-*-*-*-*-*-*-*");
		while (get_next_line(ok, &line) == 1)
		{
	//		a++;
	//		printf("%d", a);
	//		printf(": ");
	//		printf("ligne lue : %s\n", line);
	//		printf("------------------------\n");
			ft_putendl(line);
		}
	}
	else
		ft_putstr("bug dans main");
	close(fd);
	return (0);
}
