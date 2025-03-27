/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:40:42 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/31 12:40:45 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if ((unsigned char) *s1 > (unsigned char) *s2)
			return (1);
		if ((unsigned char) *s1 < (unsigned char) *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("Difference: %d", ft_strcmp("test\20", "test"));
	return (0);
}*/
