#include "get_next_line.h"

char	*read_text(int fd, char *str, char *buffer)
{
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
			if (n_bytes != BUFFER_SIZE);
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
	char	*aux;

	if (str)
	{
		pos = ft_strchr(str, '\n');
		if (pos)
		{
			aux = ft_substr(str, 0, pos - str);
			pos = ft_strchr(aux, '\n');
		}
		else
		{
			aux= ft_strdup(str);
			pos = ft_strchr(aux, '\0');
		}
		line[0] = aux;
		free(str);
		return (pos);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	int			a;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer)
	{
		if (!str)
			str = read_text(fd, str, buffer);
		if (str)
		{
			str = get_line(str, line);
			if (!*str)
				a = 0;
			else
				a = 1;
		}
		free(buffer);
	}
	a = -1;
	return (a);
}

int main()
{
	int		fd;
	int		a;
	char	**line;

	fd = open("normal.txt", O_RDONLY);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	/*a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
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
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);
	a = get_next_line(fd, line);
	printf("|%s| %d\n", line[0], a);*/
	close(fd);
}