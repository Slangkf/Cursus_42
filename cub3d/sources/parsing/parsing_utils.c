/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:58:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/04 12:35:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_strrnchr(char *s1, char *s2, int len)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	j = 0;
	while (s2[j] != '\0')
		j++;
	j--;
	while (len > 0)
	{
		if (s1[i--] != s2[j--])
			return (1);
		len--;
	}
	return (0);
}

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	ft_get_max_length(t_data *data, char **map)
{
	int	i;

	i = 0;
	if (!map || !map[0])
	{
		data->content->width = 0;
		return ;
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) > data->content->width)
				data->content->width = ft_strlen(map[i]);
		i++;
	}
}
