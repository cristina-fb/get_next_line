/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:44:53 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/16 11:44:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		ptr = malloc(len + 1);
		if (ptr)
		{
			while (*s1)
				*ptr++ = *s1++;
			while (*s2)
				*ptr++ = *s2++;
			*ptr = 0;
			return (ptr - len);
		}
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr)
	{
		while (len-- > 0)
		{
			*(ptr + i) = *(s1 + i);
			i++;
		}
		*(ptr + i) = 0;
		return (ptr);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s)
	{
		if (start < ft_strlen(s))
		{
			i = 0;
			if (len > ft_strlen(s) - start)
				len = ft_strlen(s) - start;
			ptr = malloc(len + 1);
			if (ptr)
			{
				while ((len-- > 0) && (s + start + i++))
					*(ptr + i - 1) = *(s + start + i - 1);
				*(ptr + i) = 0;
				return (ptr);
			}
		}
		else
			return (ft_strdup(""));
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s)
	{
		while (*s++)
			n++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if ((char)c == 0)
		return ((char *)s);
	return (0);
}
