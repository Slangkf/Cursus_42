/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 08:59:58 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/22 09:00:00 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_check_map_path(t_game *game)
{
	char	**cloned_map;

	cloned_map = ft_map_clone(game);
	ft_find_player_pos(cloned_map, game);
	ft_flood_fill(cloned_map, game->x_pos, game->y_pos);
	if (ft_read_map(cloned_map) == 1)
	{
		ft_free_map(cloned_map);
		return (1);
	}
	ft_free_map(cloned_map);
	return (0);
}
