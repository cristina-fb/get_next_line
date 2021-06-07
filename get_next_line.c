#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			flag;
	int			num_bytes;
	char		buffer[BUFFER_SIZE];
	static char	*str;

	flag = 1;
	if (str)
		if(!*str)
			return(0);
	while (flag)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(str, '\n') || ft_strchr(str, '\0'))
			flag = 0;
	}
	if ((num_bytes == 0) && !*(str+1))
		return (0);
	else
	{
		if (num_bytes > 0)
		{
			if (!str)
				str = ft_strdup(buffer);
			else
				str = ft_strjoin(str + 1, buffer);
		}
		if (str)
		{
			line[0] = ft_substr(str, 0, search_end_line(str) - str - 1);
			str = search_end_line(str);
			return (1);
		}
	}
	return(-1);
}

int main()
{
	int fd;
	char	**line;
	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd, line);
	printf("%s\n", *line);
	get_next_line(fd, line);
	printf("%s\n", *line);
	get_next_line(fd, line);
	printf("%s\n", *line);
	close(fd);
}
