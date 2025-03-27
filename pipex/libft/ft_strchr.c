/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:50:08 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/15 10:50:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	tab[] = "bhgbh";
	printf("Adresse premiere occurence: %p", ft_strchr(tab, 'a'));
	return (0);
}*/
