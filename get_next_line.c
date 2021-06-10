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
			if (n_bytes != BUFFER_SIZE)
				break ;
		}
		else
			return (0);
	}
	return (str);
}

char	*save_line(char *str, char **line)
{
	char	*pos;

	pos = ft_strchr(str, '\n');
	if (pos)
	{
		line[0] = ft_substr(str, 0, pos - str);
		pos = ft_strdup(ft_strchr(str, '\n') + 1);
	}
	else
	{
		line[0]= ft_strdup(str);
		pos = ft_strdup("");
	}
	free(str);
	return (pos);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	
	if (!str)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer)
			str = read_text(fd, str, buffer);
		free(buffer);
	}
	if (str)
	{
		str = save_line(str, line);
		if (ft_strlen(str))
			return(1);
		return (0);
	}
	return (-1);
}

int main()
{
	int 	fd;
	char	*line;
	int		i = 0;

	fd = open("prueba.txt", O_RDONLY);
	while (i < 2)
	{
		get_next_line(fd, &line);
		printf("|%s|\n", line);
		i++;
		free(line);
	}
	system("leaks a.out");
	close(fd);
}