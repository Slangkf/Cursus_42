/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:29 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:52:46 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	init_player_n_key_structure(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (1);
	data->player->orientation = 0;
	data->player->x_pos = 0;
	data->player->y_pos = 0;
	data->player->x_dir = 0;
	data->player->y_dir = 0;
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	return (0);
}

int	init_content_structure(t_data *data)
{
	data->content = malloc(sizeof(t_content));
	if (!data->content)
		return (1);
	data->content->scene = NULL;
	data->content->map = NULL;
	data->content->no_wall_path = NULL;
	data->content->so_wall_path = NULL;
	data->content->ea_wall_path = NULL;
	data->content->we_wall_path = NULL;
	data->content->floor_range = NULL;
	data->content->ceiling_range = NULL;
	data->content->texture_check = 0;
	data->content->width = 0;
	data->content->height = 0;
	data->content->scene_height = 0;
	data->content->nb_player = 0;
	data->content->nb_id = 0;
	return (0);
}

void	init_data_structure(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->north.img = NULL;
	data->south.img = NULL;
	data->east.img = NULL;
	data->west.img = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = -1;
	data->size_line = -1;
	data->endian = -1;
	data->floor_color = 0;
	data->ceiling_color = 0;
}

t_data	*ft_init_structures(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_print_error_exit("data malloc failed\n");
	init_data_structure(data);
	if (init_content_structure(data))
	{
		free(data);
		ft_print_error_exit("data->content malloc failed\n");
	}
	if (init_player_n_key_structure(data))
	{
		free(data->content);
		free(data);
		ft_print_error_exit("data->player malloc failed\n");
	}
	return (data);
}
