/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:58 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/21 14:44:00 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_init_map(char *argv, t_game *game)
{
	int		map_fd;
	char	*line;
	char	*map;
	char	*tmp_map;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_perror();
	map = ft_strdup("");
	game->row = 0;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		tmp_map = map;
		map = ft_strjoin(map, line);
		free(tmp_map);
		free(line);
		game->row++;
	}
	close(map_fd);
	game->map = ft_split(map, '\n');
	free(map);
	game->column = ft_strlen(game->map[0]);
}
