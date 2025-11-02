/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_manag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:20:51 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:55:02 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_close_game(t_data *data)
{
	ft_destroy_mlx(data);
	ft_free_structures(data);
	exit(0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		ft_close_game(data);
		exit(0);
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys.w = 1;
	else if (keycode == KEY_S)
		data->keys.s = 1;
	else if (keycode == KEY_A)
		data->keys.a = 1;
	else if (keycode == KEY_D)
		data->keys.d = 1;
	else if (keycode == KEY_LEFT)
		data->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		data->keys.right = 1;
	else if (keycode == KEY_ESC)
		ft_close_game(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys.w = 0;
	else if (keycode == KEY_S)
		data->keys.s = 0;
	else if (keycode == KEY_A)
		data->keys.a = 0;
	else if (keycode == KEY_D)
		data->keys.d = 0;
	else if (keycode == KEY_LEFT)
		data->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		data->keys.right = 0;
	return (0);
}

int	update(t_data *data)
{
	int	map_width;
	int	map_height;

	map_width = get_map_width(data->content->map);
	map_height = get_map_height(data->content->map);
	if (data->keys.w)
		move_forward(data, map_width, map_height);
	if (data->keys.s)
		move_backward(data, map_width, map_height);
	if (data->keys.a)
		strafe_left(data, map_width, map_height);
	if (data->keys.d)
		strafe_right(data, map_width, map_height);
	if (data->keys.left)
		rotate_left(data);
	if (data->keys.right)
		rotate_right(data);
	display_game(data);
	return (0);
}
