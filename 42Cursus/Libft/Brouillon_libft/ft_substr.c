/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:48:00 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/20 15:48:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s + start, len);
	copy[len] = '\0';
	return (copy);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*dest = (ft_substr("Hello", 4, 5));
	printf("Nouvelle chaine de caractere : %s", dest);
	return (0);
}*/
