/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:51:39 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/17 14:23:56 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_destroy_mlx(t_data *data)
{
	if (data->mlx)
	{
		if (data->north.img)
			mlx_destroy_image(data->mlx, data->north.img);
		if (data->south.img)
			mlx_destroy_image(data->mlx, data->south.img);
		if (data->east.img)
			mlx_destroy_image(data->mlx, data->east.img);
		if (data->west.img)
			mlx_destroy_image(data->mlx, data->west.img);
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
	}
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_free_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_content_structure(t_data *data)
{
	if (data->content->no_wall_path)
		free(data->content->no_wall_path);
	if (data->content->so_wall_path)
		free(data->content->so_wall_path);
	if (data->content->ea_wall_path)
		free(data->content->ea_wall_path);
	if (data->content->we_wall_path)
		free(data->content->we_wall_path);
	if (data->content->floor_range)
		ft_free_double_array(data->content->floor_range);
	if (data->content->ceiling_range)
		ft_free_double_array(data->content->ceiling_range);
	if (data->content->scene)
		ft_free_double_array(data->content->scene);
	if (data->content->map)
		ft_free_double_array(data->content->map);
	free(data->content);
}

void	ft_free_structures(t_data *data)
{
	free_content_structure(data);
	free(data->player);
	free(data);
}
