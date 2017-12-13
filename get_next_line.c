#include "get_next_line.h"

static int	retour(char *tmp, char *buf)
{
	int a;

	a = 0;
	while (a < BUFF_SIZE)
	{
		if (tmp[a] == '\n')
		{
			tmp[a] = '\0';
			return (a);
		}
		buf++;
		a++;
	}
	return (-1);
}

static int	verif(char *tmp, char *buf, char *line)
{
	int	result;

	result = 0;
	if ((result = retour(tmp, buf)) > -1)
	{
		ft_strcpy(line, tmp);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int	octet;
	int	result;
	char	*tmp;
//	char	wait[40000];

	result = 0;
	result++;
	tmp = NULL;
	if (line == NULL || fd < 0)
		return (-1);
	while ((octet = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = buf;
		result = verif(tmp, buf, line[0]);
	}
	return (1);
}
