/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:27:01 by ikayiban          #+#    #+#             */
/*   Updated: 2025/09/18 12:37:25 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_data *data, int map_width, int map_height)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x_pos + data->player->x_dir * MOVE_SPEED;
	new_y = data->player->y_pos + data->player->y_dir * MOVE_SPEED;
	if ((int)new_x >= 0 && (int)new_x < map_width
		&& data->content->map[(int)data->player->y_pos][(int)new_x] == '0')
		data->player->x_pos = new_x;
	if ((int)new_y >= 0 && (int)new_y < map_height
		&& data->content->map[(int)new_y][(int)data->player->x_pos] == '0')
		data->player->y_pos = new_y;
}

void	move_backward(t_data *data, int map_width, int map_height)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x_pos - data->player->x_dir * MOVE_SPEED;
	new_y = data->player->y_pos - data->player->y_dir * MOVE_SPEED;
	if ((int)new_x >= 0 && (int)new_x < map_width
		&& data->content->map[(int)data->player->y_pos][(int)new_x] == '0')
		data->player->x_pos = new_x;
	if ((int)new_y >= 0 && (int)new_y < map_height
		&& data->content->map[(int)new_y][(int)data->player->x_pos] == '0')
		data->player->y_pos = new_y;
}

void	strafe_left(t_data *data, int map_width, int map_height)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -data->player->y_dir;
	perp_y = data->player->x_dir;
	new_x = data->player->x_pos - perp_x * MOVE_SPEED;
	new_y = data->player->y_pos - perp_y * MOVE_SPEED;
	if ((int)new_x >= 0 && (int)new_x < map_width
		&& data->content->map[(int)data->player->y_pos][(int)new_x] == '0')
		data->player->x_pos = new_x;
	if ((int)new_y >= 0 && (int)new_y < map_height
		&& data->content->map[(int)new_y][(int)data->player->x_pos] == '0')
		data->player->y_pos = new_y;
}

void	strafe_right(t_data *data, int map_width, int map_height)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -data->player->y_dir;
	perp_y = data->player->x_dir;
	new_x = data->player->x_pos + perp_x * MOVE_SPEED;
	new_y = data->player->y_pos + perp_y * MOVE_SPEED;
	if ((int)new_x >= 0 && (int)new_x < map_width
		&& data->content->map[(int)data->player->y_pos][(int)new_x] == '0')
		data->player->x_pos = new_x;
	if ((int)new_y >= 0 && (int)new_y < map_height
		&& data->content->map[(int)new_y][(int)data->player->x_pos] == '0')
		data->player->y_pos = new_y;
}
