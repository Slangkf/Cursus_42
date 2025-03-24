/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:55:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/21 11:57:09 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_check_input(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else if (ft_strrnchr(argv[1], ".ber", 4) == 1)
		return (1);
	return (0);
}

int	ft_check_map(t_game *game)
{
	if (ft_is_rectangular(game) == 1)
		return (1);
	if (ft_closed_walls(game) == 1)
		return (1);
	if (ft_count_elements(game) == 1)
		return (1);
	if (ft_check_map_path(game) == 1)
		return (1);
	return (0);
}

int	ft_is_rectangular(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = game->column;
	if (game->row == game->column)
		return (1);
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_nb = 0;
	game->exit_nb = 0;
	game->coin_nb = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->player_nb++;
			if (game->map[i][j] == 'E')
				game->exit_nb++;
			if (game->map[i][j] == 'C')
				game->coin_nb++;
			j++;
		}
		i++;
	}
	if (game->player_nb != 1 || game->exit_nb != 1 || game->coin_nb < 1)
		return (1);
	return (0);
}

int	ft_closed_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->column)
	{
		if (game->map[0][i] != '1' || game->map[game->row - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < game->row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->column - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
