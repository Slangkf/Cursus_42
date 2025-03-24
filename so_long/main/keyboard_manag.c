/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:30:02 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/24 10:30:03 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	moove_up(t_game *game)
{
	game->map[game->y_pos][game->x_pos] = '0';
	game->y_pos--;
	game->map[game->y_pos][game->x_pos] = 'P';
}

static void	moove_down(t_game *game)
{
	game->map[game->y_pos][game->x_pos] = '0';
	game->y_pos++;
	game->map[game->y_pos][game->x_pos] = 'P';
}

static void	moove_left(t_game *game)
{
	game->map[game->y_pos][game->x_pos] = '0';
	game->x_pos--;
	game->map[game->y_pos][game->x_pos] = 'P';
}

static void	moove_right(t_game *game)
{
	game->map[game->y_pos][game->x_pos] = '0';
	game->x_pos++;
	game->map[game->y_pos][game->x_pos] = 'P';
}

int	ft_movements_manag(int keycode, t_game *game)
{
	if (keycode == 119 && game->map[game->y_pos - 1][game->x_pos] != '1')
	{
		moove_up(game);
		ft_display_map(game);
	}
	if (keycode == 115 && game->map[game->y_pos + 1][game->x_pos] != '1')
	{
		moove_down(game);
		ft_display_map(game);
	}
	if (keycode == 97 && game->map[game->y_pos][game->x_pos - 1] != '1')
	{
		moove_left(game);
		ft_display_map(game);
	}
	if (keycode == 100 && game->map[game->y_pos][game->x_pos + 1] != '1')
	{
		moove_right(game);
		ft_display_map(game);
	}
	return (0);
}
