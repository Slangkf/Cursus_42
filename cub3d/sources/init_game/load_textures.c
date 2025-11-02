/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:25:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 13:29:59 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	load_west_wall(t_data *data)
{
	data->west.img = mlx_xpm_file_to_image(data->mlx,
			data->content->we_wall_path, &data->west.width, &data->west.height);
	if (!data->west.img)
	{
		ft_destroy_mlx(data);
		ft_free_structures(data);
		ft_print_error_exit("West_wall texture loading failure\n");
	}
	data->west.addr = mlx_get_data_addr(data->west.img, &data->west.bpp,
			&data->west.line_len, &data->west.endian);
}

static void	load_east_wall(t_data *data)
{
	data->east.img = mlx_xpm_file_to_image(data->mlx,
			data->content->ea_wall_path, &data->east.width, &data->east.height);
	if (!data->east.img)
	{
		ft_destroy_mlx(data);
		ft_free_structures(data);
		ft_print_error_exit("East_wall texture loading failure\n");
	}
	data->east.addr = mlx_get_data_addr(data->east.img, &data->east.bpp,
			&data->east.line_len, &data->east.endian);
}

static void	load_south_wall(t_data *data)
{
	data->south.img = mlx_xpm_file_to_image(data->mlx,
			data->content->so_wall_path, &data->south.width,
			&data->south.height);
	if (!data->south.img)
	{
		ft_destroy_mlx(data);
		ft_free_structures(data);
		ft_print_error_exit("South_wall texture loading failure\n");
	}
	data->south.addr = mlx_get_data_addr(data->south.img, &data->south.bpp,
			&data->south.line_len, &data->south.endian);
}

static void	load_north_wall(t_data *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx,
			data->content->no_wall_path, &data->north.width,
			&data->north.height);
	if (!data->north.img)
	{
		ft_destroy_mlx(data);
		ft_free_structures(data);
		ft_print_error_exit("North_wall texture loading failure\n");
	}
	data->north.addr = mlx_get_data_addr(data->north.img, &data->north.bpp,
			&data->north.line_len, &data->north.endian);
}

void	ft_load_textures(t_data *data)
{
	load_north_wall(data);
	load_south_wall(data);
	load_east_wall(data);
	load_west_wall(data);
	ft_load_floor(data);
	ft_load_ceiling(data);
}
