/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:40:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/23 15:57:37 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_sd_file(char **sd_file, t_data *data)
{
	int	i;

	i = 0;
	while (sd_file[i])
	{
		if (ft_check_textures(sd_file[i], data) && data->content->nb_id < 6)
			return (1);
		i++;
	}
	data->content->scene_height = i;
	if (ft_check_map(data))
		return (1);
	return (0);
}

static int	extract_sd_file(char *sd_file, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(sd_file, O_RDONLY);
	if (fd == -1)
		return (ft_close_fd(), 1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->content->scene = ft_realloc(data->content->scene,
				((i) * sizeof(char *)), ((i + 2) * sizeof(char *)));
		if (!data->content->scene)
			return (ft_close_fd(), free(line), 1);
		data->content->scene[i] = ft_strdup(line);
		if (!data->content->scene[i])
			return (ft_close_fd(), free(line), 1);
		free(line);
		i++;
	}
	data->content->scene[i] = NULL;
	return (ft_close_fd(), 0);
}

int	init_scene_array(t_data *data)
{
	data->content->scene = malloc(sizeof(char *));
	if (!data->content->scene)
		return (1);
	data->content->scene[0] = NULL;
	return (0);
}

void	ft_parser(int argc, char *argv, t_data *data)
{
	if (argc != 2 || ft_strrnchr(argv, ".cub", 4))
	{
		ft_free_structures(data);
		ft_print_error_exit("Bad arguments\n");
	}
	if (init_scene_array(data) || extract_sd_file(argv, data))
	{
		ft_free_structures(data);
		ft_print_error_exit("Empty scene description file\n");
	}
	if (check_sd_file(data->content->scene, data))
	{
		ft_free_structures(data);
		ft_print_error_exit("Need a valid scene description file\n");
	}
}
