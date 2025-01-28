/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:33:09 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/14 10:33:10 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*obtain_remaining(char *basin_buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (basin_buffer[i] == '\0')
		return (free(basin_buffer), NULL);
	temp = ft_calloc((ft_strlen(basin_buffer) - i + 1), sizeof(char));
	if (!temp)
		return (NULL);
	while (basin_buffer[++i])
		temp[j++] = basin_buffer[i];
	temp[j] = '\0';
	free(basin_buffer);
	return (temp);
}

static char	*extract_line(char *basin_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (basin_buffer[i] == '\0')
		return (NULL);
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
	{
		temp[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[i] && basin_buffer[i] == '\n')
		temp[i] = '\n';
	return (temp);
}

static char	*join_and_free(char *basin_buffer, char *cup_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, cup_buffer);
	if (!temp)
		return (NULL);
	free(basin_buffer);
	return (temp);
}

static char	*read_from_file(int fd, char *basin_buffer)
{
	int		bytes_read;
	char	*cup_buffer;

	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(cup_buffer), free(basin_buffer), NULL);
		cup_buffer[bytes_read] = '\0';
		basin_buffer = join_and_free(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free(cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	basin_buffer = read_from_file(fd, basin_buffer);
	if (!basin_buffer)
		return (NULL);
	line = extract_line(basin_buffer);
	if (!line)
		return (free(basin_buffer), NULL);
	basin_buffer = obtain_remaining(basin_buffer);
	if (!basin_buffer)
		return (NULL);
	return (line);
}
