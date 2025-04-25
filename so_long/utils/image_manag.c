/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:04:30 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/22 12:04:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_images(t_game *game)
{
	ft_load_wall_img(game);
	ft_load_floor_img(game);
	ft_load_player_img(game);
	ft_load_exit_img(game);
	ft_load_coin_img(game);
}

static void	img_to_wdw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * 32, y * 32);
}

void	ft_display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				img_to_wdw(game, game->wall, j, i);
			if (game->map[i][j] == '0')
				img_to_wdw(game, game->floor, j, i);
			if (game->map[i][j] == 'P')
				img_to_wdw(game, game->player, j, i);
			if (game->map[i][j] == 'C')
				img_to_wdw(game, game->coin, j, i);
			if (game->map[i][j] == 'E')
				img_to_wdw(game, game->exit, j, i);
			j++;
		}
		i++;
	}
}
