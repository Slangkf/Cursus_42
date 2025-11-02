/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:48:34 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/03 10:06:03 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_close_fd(void)
{
	int	i;

	i = 3;
	while (i <= 1023)
		close(i++);
}

void	ft_print_error_exit(char *mess)
{
	write(2, "Error\n", 6);
	while (*mess)
		write(2, mess++, 1);
	exit(1);
}

void	ft_print_error(char *mess)
{
	write(2, "Error\n", 6);
	while (*mess)
		write(2, mess++, 1);
}
