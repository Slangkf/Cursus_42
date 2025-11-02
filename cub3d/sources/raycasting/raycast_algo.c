/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:45:02 by ikayiban          #+#    #+#             */
/*   Updated: 2025/09/24 09:42:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_ray_direction(t_data *data, t_ray *ray, int x)
{
	double	camera_x;
	double	plane_x;
	double	plane_y;

	camera_x = 2 * x / (double)WIDTH - 1;
	plane_x = -data->player->y_dir * 0.66;
	plane_y = data->player->x_dir * 0.66;
	ray->dir_x = data->player->x_dir + plane_x * camera_x;
	ray->dir_y = data->player->y_dir + plane_y * camera_x;
	ray->map_x = (int)data->player->x_pos;
	ray->map_y = (int)data->player->y_pos;
	if (ray->dir_x == 0)
		ray->dir_x = 1e-30;
	if (ray->dir_y == 0)
		ray->dir_y = 1e-30;
	ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->dir_y);
	ray->hit = 0;
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
	init_ray_direction(data, ray, x);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->x_pos - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->x_pos)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->y_pos - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->y_pos)
			* ray->delta_dist_y;
	}
}

void	dda_step(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	dda_algo(t_data *data, t_ray *ray)
{
	int	map_w;
	int	map_h;
	int	iter;
	int	max_iter;

	map_w = get_map_width(data->content->map);
	map_h = get_map_height(data->content->map);
	max_iter = map_w + map_h;
	iter = 0;
	while (ray->hit == 0 && iter < max_iter)
	{
		dda_step(ray);
		if (ray->map_x < 0 || ray->map_x >= map_w || ray->map_y < 0
			|| ray->map_y >= map_h
			|| data->content->map[ray->map_y][ray->map_x] == '1'
			|| data->content->map[ray->map_y][ray->map_x] == 32)
			ray->hit = 1;
		iter++;
	}
	if (ray->hit == 0)
	{
		ray->hit = 1;
		ray->perp_wall_dist = 1000.0;
	}
}

void	calculate_wall_distance(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player->x_pos + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player->y_pos + (1
					- ray->step_y) / 2) / ray->dir_y;
}
