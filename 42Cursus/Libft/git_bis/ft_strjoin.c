/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:07 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/21 12:13:10 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*result;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	result = malloc (sizeof(char) * (ls1 + ls2 + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, ls1);
	ft_memcpy(result + ls1, s2, ls2);
	result[ls1 + ls2] = '\0';
	return (result);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	s1[] = "Hello, ";
	char	s2[] = "World !";
	char	*result = (ft_strjoin(s1, s2));

	printf("Nouvelle chaine de caractere : %s", result);
	return (0);
}*/
