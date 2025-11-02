/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:34:07 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/23 13:09:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	append_range(int id, int range_count, char **result, t_data *data)
{
	if (id == 'F' && range_count == 3 && !data->content->floor_range)
	{
		data->content->floor_range = result;
		return (0);
	}
	if (id == 'C' && range_count == 3 && !data->content->ceiling_range)
	{
		data->content->ceiling_range = result;
		return (0);
	}
	else
		return (ft_free_double_array(result), 1);
}

static int	check_line(char *line, char id)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == id || line[i] == 32 || line[i] == 9))
		i++;
	if (!line[i])
		return (-1);
	while (line[i])
	{
		if (line[i] == '-')
			return (-1);
		if (!ft_isdigit(line[i]) && line[i] != ',' && !ft_isspace(line[i]))
			return (-1);
		i++;
	}
	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	return (i);
}

int	ft_check_range(char *line, char id, t_data *data)
{
	char	**result;
	int		i;

	if (id != 'F' && id != 'C')
		return (0);
	if (check_line(line, id) == -1)
		return (1);
	result = ft_split(line + check_line(line, id), ',');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		if (ft_atoi(result[i]) < 0 || ft_atoi(result[i]) > 255)
			return (ft_free_double_array(result), 1);
		i++;
	}
	return (append_range(id, i, result, data));
}
