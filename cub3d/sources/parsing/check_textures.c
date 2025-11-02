/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:00:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/23 15:30:40 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_id(char *line, char id, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	if (id == 'N' && (line[i + 1] != 'O' || !ft_isspace(line[i + 2])))
		return (1);
	else if (id == 'S' && (line[i + 1] != 'O' || !ft_isspace(line[i + 2])))
		return (1);
	else if (id == 'E' && (line[i + 1] != 'A' || !ft_isspace(line[i + 2])))
		return (1);
	else if (id == 'W' && (line[i + 1] != 'E' || !ft_isspace(line[i + 2])))
		return (1);
	else if (id == 'F' && !ft_isspace(line[i + 1]))
		return (1);
	else if (id == 'C' && !ft_isspace(line[i + 1]))
		return (1);
	data->content->nb_id++;
	return (0);
}

static char	*copy_path(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*path;

	i = 0;
	j = 0;
	len = 0;
	while (line[i] && line[i] != '.')
		i++;
	len = ft_strlen(line) - i;
	path = malloc(sizeof(char) * (len));
	if (!path)
		return (NULL);
	while (line[i] && line[i] != '\n')
		path[j++] = line[i++];
	path[j] = '\0';
	return (path);
}

static int	extract_path(char *line, char id, t_data *data)
{
	if (id == 'N')
	{
		data->content->no_wall_path = copy_path(line);
		if (!data->content->no_wall_path)
			return (1);
	}
	if (id == 'S')
	{
		data->content->so_wall_path = copy_path(line);
		if (!data->content->so_wall_path)
			return (1);
	}
	if (id == 'E')
	{
		data->content->ea_wall_path = copy_path(line);
		if (!data->content->ea_wall_path)
			return (1);
	}
	if (id == 'W')
	{
		data->content->we_wall_path = copy_path(line);
		if (!data->content->we_wall_path)
			return (1);
	}
	return (0);
}

int	ft_check_path(char *line, char id, t_data *data)
{
	if (id == 'F' || id == 'C')
		return (0);
	if (id == 'N' && !data->content->no_wall_path)
		return (extract_path(line, id, data));
	if (id == 'S' && !data->content->so_wall_path)
		return (extract_path(line, id, data));
	if (id == 'E' && !data->content->ea_wall_path)
		return (extract_path(line, id, data));
	if (id == 'W' && !data->content->we_wall_path)
		return (extract_path(line, id, data));
	return (1);
}

int	ft_check_textures(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	if (line[i] == '\n')
		return (0);
	if (!ft_isalpha(line[i]))
		return (1);
	if (ft_check_path(line, line[i], data))
		return (1);
	if (ft_check_range(line, line[i], data))
		return (1);
	if (ft_check_id(line, line[i], data))
		return (1);
	return (0);
}
