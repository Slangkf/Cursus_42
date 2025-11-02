/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:54:57 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/03 10:04:33 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_load_ceiling(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->content->ceiling_range[0]);
	g = ft_atoi(data->content->ceiling_range[1]);
	b = ft_atoi(data->content->ceiling_range[2]);
	data->ceiling_color = (r << 16) | (g << 8) | b;
}

void	ft_load_floor(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->content->floor_range[0]);
	g = ft_atoi(data->content->floor_range[1]);
	b = ft_atoi(data->content->floor_range[2]);
	data->floor_color = (r << 16) | (g << 8) | b;
}
