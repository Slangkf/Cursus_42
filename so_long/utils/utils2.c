/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 09:39:07 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/22 09:39:09 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static int	new_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

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

char	**ft_new_split(char const *s, char c, t_game *game)
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
		if (*s != c && new_isspace(*s) == 0)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i++] = ft_sub_dup(start, s - start);
			game->row++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
