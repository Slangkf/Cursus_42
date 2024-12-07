/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:27:37 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/14 11:14:30 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	dst[20];

	printf("Longueur de src: %zu", ft_strlcpy(dst, "Hello, World !", 10));
	printf("String dst: %s", dst);
	return (0);
}*/
