/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:32:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/13 13:32:29 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_from_infile(int infile_fd, int pipe_fd)
{	
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc(4096, sizeof(char));
	if (!buffer)
		ft_print_error();
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(infile_fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			free(buffer);
			ft_print_error();
		}
		write(pipe_fd, buffer, bytes_read);
	}
	free(buffer);
}

void	read_from_stdin(int pipe_fd, int outfile_fd)
{	
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc(4096, sizeof(char));
	if (!buffer)
		ft_print_error();
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(pipe_fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			free(buffer);
			ft_print_error();
		}
		write(outfile_fd, buffer, bytes_read);
	}
	free(buffer);
}

void	close_pipe_fd(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
