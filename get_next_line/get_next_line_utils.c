/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:33:20 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/14 10:33:22 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	size_t	i;
	char	*memory;

	bytes = nmemb * size;
	if (size != 0 && ((bytes / size) != nmemb))
		return (NULL);
	memory = malloc (bytes);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dst;

	size = ft_strlen(s1) + ft_strlen(s2);
	dst = ft_calloc(size + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
