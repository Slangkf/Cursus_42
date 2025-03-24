/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manag2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:49:54 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/24 12:49:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_load_wall_img(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	if (!game->wall)
	{
		ft_free_struc(game);
		ft_perror();
	}
}

void	ft_load_floor_img(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	if (!game->floor)
	{
		ft_free_struc(game);
		ft_perror();
	}
}

void	ft_load_player_img(t_game *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	if (!game->player)
	{
		ft_free_struc(game);
		ft_perror();
	}
}

void	ft_load_exit_img(t_game *game)
{
	int	width;
	int	height;

	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	if (!game->exit)
	{
		ft_exit_solong(game);
		ft_perror();
	}
}

void	ft_load_coin_img(t_game *game)
{
	int	width;
	int	height;

	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&width, &height);
	if (!game->coin)
	{
		ft_free_struc(game);
		ft_perror();
	}
}
