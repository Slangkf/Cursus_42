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

#include "../header/so_long.h"

void	ft_find_player_pos(char **cloned_map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (cloned_map[i] != NULL)
	{
		j = 0;
		while (cloned_map[i][j] != '\0')
		{
			if (cloned_map[i][j] == 'P')
			{
				game->x_pos = j;
				game->y_pos = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(char **cloned_map, int x, int y)
{
	if (cloned_map[y][x] == '1' || cloned_map[y][x] == 'D')
		return ;
	cloned_map[y][x] = 'D';
	ft_flood_fill(cloned_map, x + 1, y);
	ft_flood_fill(cloned_map, x - 1, y);
	ft_flood_fill(cloned_map, x, y + 1);
	ft_flood_fill(cloned_map, x, y - 1);
}

int	ft_read_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				return (1);
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_map_clone(t_game *game)
{
	char	**cloned_map;
	int		i;

	i = 0;
	cloned_map = malloc(sizeof(char *) * (game->row + 1));
	if (!cloned_map)
		ft_perror();
	i = 0;
	while (i < game->row)
	{
		cloned_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	cloned_map[i] = NULL;
	return (cloned_map);
}
