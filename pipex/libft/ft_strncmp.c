/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:27:29 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/15 14:27:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
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
	printf("Difference: %d", ft_strncmp("test\200", "test\0", 6));
	return (0);
}*/
