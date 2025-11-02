/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:47:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 15:05:44 by ikayiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_direction(t_player *p)
{
	if (p->orientation == 'N')
	{
		p->x_dir = 0;
		p->y_dir = -1;
	}
	else if (p->orientation == 'S')
	{
		p->x_dir = 0;
		p->y_dir = 1;
	}
	else if (p->orientation == 'E')
	{
		p->x_dir = 1;
		p->y_dir = 0;
	}
	else if (p->orientation == 'W')
	{
		p->x_dir = -1;
		p->y_dir = 0;
	}
}

void	set_player_position(t_player *player, int x, int y, t_data *data)
{
	player->x_pos = x + 0.5;
	player->y_pos = y + 0.5;
	player->orientation = data->content->map[y][x];
	set_player_direction(player);
	data->content->map[y][x] = '0';
}

void	init_player_from_map(t_data *data)
{
	int		x;
	int		y;
	char	c;

	if (!data || !data->content || !data->content->map)
		ft_print_error_exit("Error\n");
	y = 0;
	while (data->content->map[y])
	{
		x = 0;
		while (data->content->map[y][x])
		{
			c = data->content->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player_position(data->player, x, y, data);
				return ;
			}
			x++;
		}
		y++;
	}
	ft_print_error_exit("No player found in map\n");
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_structures(data);
		ft_print_error_exit("mlx_init failed\n");
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->win)
	{
		ft_destroy_mlx(data);
		ft_free_structures(data);
		ft_print_error_exit("mlx_new_window failed\n");
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	init_player_from_map(data);
	ft_load_textures(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_init_structures();
	ft_parser(argc, argv[1], data);
	init_game(data);
	display_game(data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0L, ft_close_game, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
	ft_close_game(data);
	return (0);
}
