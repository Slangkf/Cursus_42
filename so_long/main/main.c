/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:09:33 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/14 12:09:34 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->column * 32,
			game->row * 32, "so_long");
	ft_load_images(game);
	ft_display_map(game);
}	

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (ft_check_input(argc, argv) == 1)
		return (free(game), write(2, "Error: invalid input\n", 21));
	ft_init_map(argv[1], game);
	if (ft_check_map(game) == 1)
		return (ft_free_struc(game), write(2, "Error: invalid map\n", 19));
	init_game(game);
	mlx_key_hook(game->window, &ft_movements_manag, game);
	mlx_loop(game->mlx);
	ft_free_struc(game);
	return (0);
}
