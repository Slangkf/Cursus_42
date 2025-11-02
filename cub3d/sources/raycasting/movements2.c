/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:33:19 by ikayiban          #+#    #+#             */
/*   Updated: 2025/09/18 14:43:34 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	if (!map)
		return (0);
	while (map[height])
		height++;
	return (height);
}

void	rotate_left(t_data *data)
{
	double	old_x;

	old_x = data->player->x_dir;
	data->player->x_dir = data->player->x_dir * cos(-ROT_SPEED)
		- data->player->y_dir * sin(-ROT_SPEED);
	data->player->y_dir = old_x * sin(-ROT_SPEED) + data->player->y_dir
		* cos(-ROT_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_x;

	old_x = data->player->x_dir;
	data->player->x_dir = data->player->x_dir * cos(ROT_SPEED)
		- data->player->y_dir * sin(ROT_SPEED);
	data->player->y_dir = old_x * sin(ROT_SPEED) + data->player->y_dir
		* cos(ROT_SPEED);
}
