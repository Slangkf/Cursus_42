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

#include "../so_long.h"

static void	moove_up(t_game *game)
{
	if (game->map[game->y_pos - 1][game->x_pos] == 'C')
		game->coin_nb--;
	if (game->map[game->y_pos - 1][game->x_pos] != 'E')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->y_pos--;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_display_map(game);
	}
	else if (game->map[game->y_pos - 1][game->x_pos] == 'E'
		&& game->coin_nb == 0)
	{
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_win_game(game);
	}
	else
		return ;
}

static void	moove_down(t_game *game)
{
	if (game->map[game->y_pos + 1][game->x_pos] == 'C')
		game->coin_nb--;
	if (game->map[game->y_pos + 1][game->x_pos] != 'E')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->y_pos++;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_display_map(game);
	}
	else if (game->map[game->y_pos + 1][game->x_pos] == 'E'
		&& game->coin_nb == 0)
	{
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_win_game(game);
	}
	else
		return ;
}

static void	moove_left(t_game *game)
{
	if (game->map[game->y_pos][game->x_pos - 1] == 'C')
		game->coin_nb--;
	if (game->map[game->y_pos][game->x_pos - 1] != 'E')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos--;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_display_map(game);
	}
	else if (game->map[game->y_pos][game->x_pos - 1] == 'E'
		&& game->coin_nb == 0)
	{
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_win_game(game);
	}
	else
		return ;
}

static void	moove_right(t_game *game)
{
	if (game->map[game->y_pos][game->x_pos + 1] == 'C')
		game->coin_nb--;
	if (game->map[game->y_pos][game->x_pos + 1] != 'E')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos++;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_display_map(game);
	}
	else if (game->map[game->y_pos][game->x_pos + 1] == 'E'
		&& game->coin_nb == 0)
	{
		ft_printf("Count moves: %d\n", ++game->move_nb);
		ft_win_game(game);
	}
	else
		return ;
}

int	ft_keyboard_manag(int keycode, t_game *game)
{
	if (keycode == 119 && game->map[game->y_pos - 1][game->x_pos] != '1')
		moove_up(game);
	if (keycode == 115 && game->map[game->y_pos + 1][game->x_pos] != '1')
		moove_down(game);
	if (keycode == 97 && game->map[game->y_pos][game->x_pos - 1] != '1')
		moove_left(game);
	if (keycode == 100 && game->map[game->y_pos][game->x_pos + 1] != '1')
		moove_right(game);
	if (keycode == 65307)
		ft_close_game(game);
	return (0);
}
