/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:47:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/24 09:28:10 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_map_content(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && !ft_is_player(map[i][j])
				&& map[i][j] != 32 && map[i][j] != 10)
				return (0);
			if (ft_is_player(map[i][j]))
			{
				if (++data->content->nb_player > 1)
					return (0);
				data->player->x_pos = j;
				data->player->y_pos = i;
				data->player->orientation = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (data->content->nb_player);
}

static int	check_empty_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && ft_isspace(map[i][j]))
			j++;
		if (map[i][j] == '\0')
			return (1);
		else
			i++;
	}
	return (0);
}

static int	find_map(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	if (data->content->nb_id > 0 && (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == 'F'
			|| line[i] == 'C'))
	{
		data->content->nb_id--;
		return (1);
	}
	return (0);
}

static int	extract_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->content->scene[i] && find_map(data->content->scene[i], data))
		i++;
	if (!data->content->scene[i])
		return (1);
	data->content->map = malloc(sizeof(char *)
			* ((data->content->scene_height - i) + 1));
	if (!data->content->map)
		return (1);
	j = 0;
	while (data->content->scene[i])
	{
		data->content->map[j] = ft_strdup(data->content->scene[i]);
		if (!data->content->map[j])
			return (1);
		j++;
		i++;
	}
	data->content->map[j] = NULL;
	data->content->height = j + 1;
	ft_get_max_length(data, data->content->map);
	return (0);
}

int	ft_check_map(t_data *data)
{
	if (!data->content->scene || !data->content->scene[0])
		return (1);
	if (!data->content->map && extract_map(data))
		return (1);
	if (check_empty_line(data->content->map))
		return (1);
	if (!check_map_content(data, data->content->map))
		return (1);
	if (ft_check_walls(data))
		return (1);
	return (0);
}
