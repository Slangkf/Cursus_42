/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:49:01 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/29 09:49:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
#include <unistd.h>

int	main(void)
{
	ft_putendl_fd("Hello, World !", 1);
	return (0);
}*/
