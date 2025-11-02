/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:56:55 by ikayiban          #+#    #+#             */
/*   Updated: 2025/09/18 14:59:02 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_display_back(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				*(unsigned int *)(data->addr + (y * data->size_line + x
							* (data->bits_per_pixel
								/ 8))) = data->ceiling_color;
			else
				*(unsigned int *)(data->addr + (y * data->size_line + x
							* (data->bits_per_pixel / 8))) = data->floor_color;
			x++;
		}
		y++;
	}
}

void	render_3d(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, &ray, x);
		dda_algo(data, &ray);
		calculate_wall_distance(data, &ray);
		draw_wall_column(data, x, &ray);
		x++;
	}
}

void	display_game(t_data *data)
{
	ft_display_back(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
