/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:01:46 by ikayiban          #+#    #+#             */
/*   Updated: 2025/09/18 14:58:30 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = data->addr + (y * data->size_line + x * (data->bits_per_pixel
					/ 8));
		*(int *)pixel = color;
	}
}

void	calcul_column_dims(t_ray *ray, t_wall_calc *wc)
{
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 0.001;
	wc->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	wc->draw_start = -(wc->line_height) / 2 + HEIGHT / 2;
	if (wc->draw_start < 0)
		wc->draw_start = 0;
	wc->draw_end = wc->line_height / 2 + HEIGHT / 2;
	if (wc->draw_end >= HEIGHT)
		wc->draw_end = HEIGHT - 1;
}

void	select_texture(t_data *data, t_ray *ray, t_wall_calc *wc)
{
	double	wall_x;

	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			wc->current_tex = data->east;
		else
			wc->current_tex = data->west;
		wall_x = data->player->y_pos + ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		if (ray->step_y > 0)
			wc->current_tex = data->south;
		else
			wc->current_tex = data->north;
		wall_x = data->player->x_pos + ray->perp_wall_dist * ray->dir_x;
	}
	wall_x -= floor(wall_x);
	wc->tex_x = (int)(wall_x * (double)wc->current_tex.width);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		wc->tex_x = wc->current_tex.width - wc->tex_x - 1;
}

void	draw_column(t_data *data, int x, t_wall_calc *wc)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		tex_offset;

	step = 1.0 * wc->current_tex.height / wc->line_height;
	tex_pos = (wc->draw_start - HEIGHT / 2 + wc->line_height / 2) * step;
	y = wc->draw_start;
	while (y <= wc->draw_end)
	{
		tex_y = (int)tex_pos % wc->current_tex.height;
		tex_pos += step;
		tex_offset = tex_y * wc->current_tex.line_len + wc->tex_x
			* (wc->current_tex.bpp / 8);
		if (wc->tex_x >= 0 && wc->tex_x < wc->current_tex.width && tex_y >= 0
			&& tex_y < wc->current_tex.height)
			put_pixel_to_img(data, x, y, *(unsigned int *)(wc->current_tex.addr
					+ tex_offset));
		y++;
	}
}

void	draw_wall_column(t_data *data, int x, t_ray *ray)
{
	t_wall_calc	wc;

	calcul_column_dims(ray, &wc);
	select_texture(data, ray, &wc);
	draw_column(data, x, &wc);
}
