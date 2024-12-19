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

#include "get_next_line.h"
#include <string.h>

static char	*obtain_remaining(char *basin_buffer)
{
	size_t	len;
	size_t	i;
	char	*temp;

	if (!basin_buffer)
		return (NULL);
	len = ft_strlen(basin_buffer);
	printf("%zu", len);
	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (basin_buffer[i] == '\0')
		return (free(basin_buffer), NULL);
	temp = ft_substr(basin_buffer, i + 1, len - i - 1);
	if (!temp)
		free(temp);
	free(basin_buffer);
	return (temp);
}

static char	*extract_line(char *basin_buffer)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*temp;

	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (basin_buffer[i] == '\0')
		return (free(basin_buffer), NULL);
	temp = ft_calloc(i + 2, sizeof(char));
	if (!temp)
		return (free(basin_buffer), NULL);
	j = 0;
	k = 0;
	while (basin_buffer[j] && basin_buffer[j] != '\n')
		temp[k++] = basin_buffer[j++];
	temp[k] = '\n';
	return (temp);
}

static char	*read_from_file(int fd, char *basin_buffer)
{
	int		bytes_read;
	char	*cup_buffer;
	char	*temp;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		cup_buffer[bytes_read] = '\0';
		temp = ft_strjoin(basin_buffer, cup_buffer);
		if (!temp)
			return (free(temp), NULL);
		free(basin_buffer);
		basin_buffer = temp;
		if (ft_strchr(basin_buffer, '\n'))
			break ;
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	}
	free(cup_buffer);
	if (bytes_read <= 0 && (!basin_buffer || *basin_buffer == '\0'))
		return (free(basin_buffer), NULL);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	basin_buffer = ft_calloc(1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(basin_buffer);
		basin_buffer = NULL;
		return (NULL);
	}
	if (!basin_buffer)
		return (NULL);
	basin_buffer = read_from_file(fd, basin_buffer);
	if (!basin_buffer || *basin_buffer == '\0')
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	if (!line && basin_buffer)
		free(basin_buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		count;
	char	*output_line;

	count = 1;
	fd = open("francitest.txt", O_RDONLY);
	//while (1)
	//{
		output_line = get_next_line(fd);
		//if (output_line == NULL)
			//break ;
		printf("[%d]:%s", count++, output_line);
		//free(output_line);
		//output_line = NULL;
	//}
	close(fd);
	return (0);
}*/
