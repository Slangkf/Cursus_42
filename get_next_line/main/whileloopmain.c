/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whileloopmain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:55:40 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/27 10:55:42 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*temp;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("line : %s", temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (0);
}
