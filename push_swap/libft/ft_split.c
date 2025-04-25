/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:27:37 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/23 10:27:42 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_sub(const char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (i);
}

static char	*ft_sub_dup(char const *start, size_t len)
{
	char	*dup;

	dup = malloc (len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, start, len);
	dup[len] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	int			s_count;
	int			i;
	char		**split;
	const char	*start;

	s_count = ft_count_sub(s, c);
	split = malloc (sizeof(char *) * (s_count + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i++] = ft_sub_dup(start, s - start);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char const	s[] = "Hello, World !";
	char		c = ' ';
	char		**result;

	result = ft_split(s, c);
	if (result == NULL)
		return (1);
	// Affiche chaque chaîne retournée
	for (int i = 0; result[i] != NULL; i++)
		printf("result[%d] = %s\n", i, result[i]);

	// Libère chaque chaîne car ft_split alloue dynamiquement
	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);

	// Libère le tableau principal
	free(result);
	return (0);
}*/
