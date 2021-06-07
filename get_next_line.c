#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*str;

	if (str)
		if(!*str)
			return(0);
	read_line(fd, str);
	printf("%s", num_bytes,str);
	return(-1);
}

int main()
{
	int		fd;
	char	**line;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd, line);
	close(fd);
}