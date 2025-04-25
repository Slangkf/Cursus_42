/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:14 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/25 12:55:15 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_good_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
			&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
			&& game->map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
