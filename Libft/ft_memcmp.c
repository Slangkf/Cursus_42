/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:07:21 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/16 12:07:23 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const unsigned char	s1[] = "Hello !";
	const unsigned char	s2[] = "Hello!";
	size_t	n = 7;
	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);
}*/
