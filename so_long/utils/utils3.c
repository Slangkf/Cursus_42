/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:25:57 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/24 15:44:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_game(t_game *game)
{
	write(1, "Nice try budy, see you next time.\n", 34);
	ft_exit_solong(game);
	ft_free_struc(game);
	exit(0);
}

int	ft_win_game(t_game *game)
{
	write(1, "Well done!! Are you a pro gamer?\n", 33);
	ft_exit_solong(game);
	ft_free_struc(game);
	exit(0);
}

void	ft_exit_solong(t_game *game)
{
	if (game->mlx)
	{
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->coin)
			mlx_destroy_image(game->mlx, game->coin);
	}
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}
