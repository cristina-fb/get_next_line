/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:43:47 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/16 15:07:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_text(int fd, char *str, char *buffer)
{
	char	*aux;
	int		n_bytes;

	n_bytes = read(fd, buffer, BUFFER_SIZE);
	if ((n_bytes == 0) && !str)
		return (ft_strdup(""));
	if (n_bytes < 0)
		return (0);
	while (n_bytes > 0)
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
		if (ft_strchr(str, '\n'))
			break ;
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (str);
}

char	*save_line(char *str, char **line)
{
	char	*pos;

	pos = ft_strchr(str, '\n');
	if (pos)
	{
		*line = ft_substr(str, 0, pos - str);
		pos = ft_strdup(pos + 1);
	}
	else
	{
		*line = ft_strdup(str);
		pos = 0;
	}
	free(str);
	return (pos);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer)
		str = read_text(fd, str, buffer);
	free(buffer);
	if (str)
	{
		str = save_line(str, line);
		if (str)
			return (1);
		free(str);
		return (0);
	}
	return (-1);
}
