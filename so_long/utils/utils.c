/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:31:08 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/19 11:31:09 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_perror(void)
{
	perror("Error");
	exit(1);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

void	ft_free_struc(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	free(game);
}

int	ft_strrnchr(char *s1, char *s2, int len)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	j = 0;
	while (s2[j] != '\0')
		j++;
	j--;
	while (len > 0)
	{
		if (s1[i--] != s2[j--])
			return (1);
		len--;
	}
	return (0);
}

int	ft_new_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == 0)
			return (1);
		s++;
	}
	return (0);
}
