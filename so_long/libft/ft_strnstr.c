/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:44:46 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/18 12:44:49 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	l_len = 0;
	while (little[l_len] != '\0')
		l_len++;
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (j == l_len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	big[] = "svdb !";
	const char	little[] = "!";
	char	*ptr;
	int	result;
	
	ptr = ft_strnstr(big, little, sizeof(big));
	if (*little == '\0')
	{
		printf("%s\n", big);
		return (0);
	}
	if (ptr != NULL)
	{
		result = (int)(ptr - big + 1);
		printf("little: %s found at position %d\n", little, result);
	}
	else
		printf("Little introuvable dans big\n");
	return (0);
}*/
