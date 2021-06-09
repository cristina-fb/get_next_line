#include "get_next_line.h"

char	*read_text(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		n_bytes;

	while (1)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes >= 0)
		{
			buffer[n_bytes] = 0;
			if (!str)
				str = ft_strdup(buffer);
			else
			{
				aux = ft_strjoin(str, buffer);
				free(str);
				str = aux;
			}
			if (n_bytes != BUFFER_SIZE)
				break ;
		}
		else
			return (0);
	}
	return (str);
}

char	*get_line(char *str, char **line)
{
	char	*pos;

	if (str)
	{
		pos = ft_strchr(str, '\n');
		if (pos)
			line[0] = ft_substr(str, 0, pos - str);
		else
		{
			pos = ft_strchr(str, '\0');
			line[0] = ft_substr(str, 0, pos - str);
		}
		return (pos);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;

	if (str && !*str)
		return (0);
	else
	{
		if (!str)
			str = read_text(fd, str);
		else
			str++;
		if (str)
		{
			str = get_line(str, line);
			return (1);
		}
	}
	return (-1);
}

int main()
{
	int		fd;
	int		a;
	char	**line;

	fd = open("prueba.txt", O_RDONLY);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	close(fd);
}