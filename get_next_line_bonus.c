/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:44:32 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/16 12:32:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		}
		if (n_bytes != BUFFER_SIZE)
			break ;
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
		pos = ft_strdup(pos);
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
	static char	*str[4096];
	char		*aux;
	char		*buffer;
	
	if (!str[fd] && (fd >= 0))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer)
			str[fd] = read_text(fd, str[fd], buffer);
		free(buffer);
	}
	if (str[fd] && (fd >= 0))
	{
		str[fd] = save_line(str[fd], line);
		if (ft_strlen(str[fd]))
		{
			aux = ft_strdup(str[fd] + 1);
			free(str[fd]);
			str[fd] = aux;
			return(1);
		}
		return (0);
	}
	return (-1);
}