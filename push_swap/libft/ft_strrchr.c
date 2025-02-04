/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:10 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/15 13:35:12 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;

	ps = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
		{
			ps = (char *)s;
		}
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return (ps);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	tab[] = "abba";
	printf("Adresse derniere occurence: %p", ft_strrchr(tab, 'a'));
	return (0);
}*/
