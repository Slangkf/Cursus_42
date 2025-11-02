/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:16:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/24 09:33:59 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	flood_fill(char **cloned_map, int x, int y)
{
	if (y < 0 || x < 0 || !cloned_map[y] || !cloned_map[y][x])
		return (0);
	if (ft_is_player(cloned_map[y][x]) || cloned_map[y][x] == '0')
		return (1);
	if (cloned_map[y][x] == '~' || cloned_map[y][x] == '1')
		return (0);
	cloned_map[y][x] = '~';
	if (flood_fill(cloned_map, x + 1, y))
		return (1);
	if (flood_fill(cloned_map, x - 1, y))
		return (1);
	if (flood_fill(cloned_map, x, y + 1))
		return (1);
	if (flood_fill(cloned_map, x, y - 1))
		return (1);
	return (0);
}

static void	preparing_cloned_map(t_data *data, char **cloned_map)
{
	size_t	j;
	int		i;

	j = 0;
	while (j < (data->content->width + 2))
	{
		cloned_map[0][j] = '.';
		cloned_map[data->content->height][j++] = '.';
	}
	i = 0;
	while (data->content->map[i])
	{
		j = 0;
		cloned_map[i + 1][j] = '.';
		while (data->content->map[i][j])
		{
			cloned_map[i + 1][j + 1] = data->content->map[i][j];
			j++;
		}
		while (j < (data->content->width + 1))
			cloned_map[i + 1][++j] = '.';
		i++;
	}
}

static char	**cloning_map(t_data *data, char **cloned_map)
{
	int	i;

	cloned_map = malloc(sizeof(char *) * (data->content->height + 2));
	if (!cloned_map)
		return (NULL);
	i = 0;
	while (i < (data->content->height + 1))
	{
		cloned_map[i] = ft_calloc(data->content->width + 3, sizeof(char));
		if (!cloned_map[i])
			return (NULL);
		i++;
	}
	cloned_map[i] = NULL;
	preparing_cloned_map(data, cloned_map);
	return (cloned_map);
}

int	ft_check_walls(t_data *data)
{
	char	**cloned_map;

	cloned_map = NULL;
	cloned_map = cloning_map(data, cloned_map);
	if (!cloned_map)
		return (1);
	if (flood_fill(cloned_map, 0, 0))
		return (ft_free_double_array(cloned_map), 1);
	return (ft_free_double_array(cloned_map), 0);
}
