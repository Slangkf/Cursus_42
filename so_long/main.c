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

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->move_nb = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_free_struc(game);
		ft_exit_solong(game);
		ft_print_error("Error: mlx_init failure\n");
	}
	game->window = mlx_new_window(game->mlx, game->column * 32,
			game->row * 32, "so_long");
	if (!game->window)
	{
		ft_free_struc(game);
		ft_exit_solong(game);
		ft_print_error("Error: mlx_window failure\n");
	}
	ft_load_images(game);
	ft_display_map(game);
}

static int	get_map(int map_fd, t_game *game, char *map)
{
	char	*line;
	char	*tmp_map;

	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		tmp_map = map;
		map = ft_strjoin(map, line);
		if (!map)
			return (1);
		free(tmp_map);
		free(line);
	}
	close(map_fd);
	game->map = ft_new_split(map, '\n', game);
	if (!game->map[0])
		return (1);
	free(map);
	return (0);
}

static void	init_map(char *argv, t_game *game)
{
	int		map_fd;
	char	*map;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
	{
		ft_free_struc(game);
		ft_print_error("Error: open map failure\n");
	}
	map = ft_strdup("");
	if (!map)
	{
		ft_free_struc(game);
		ft_print_error("Error: memory allocation failure\n");
	}
	game->row = 0;
	if (get_map(map_fd, game, map) == 1)
	{
		free(map);
		ft_free_struc(game);
		ft_print_error("Error: get_map failure\n");
	}
	game->column = ft_strlen(game->map[0]);
}

static void	init_struc(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->player = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->coin = NULL;
	game->exit = NULL;
	game->map = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (ft_check_input(argc, argv) == 1)
		return (write(2, "Error: invalid input\n", 21));
	game = malloc(sizeof(t_game));
	if (!game)
		return (write(2, "Error: memory allocation failure\n", 33));
	init_struc(game);
	init_map(argv[1], game);
	if (ft_check_map(game) == 1)
		return (ft_free_struc(game), write(2, "Error: invalid map\n", 19));
	init_game(game);
	mlx_key_hook(game->window, &ft_keyboard_manag, game);
	mlx_hook(game->window, 17, 0L, &ft_close_game, game);
	mlx_loop(game->mlx);
	ft_free_struc(game);
	ft_exit_solong(game);
	return (0);
}
