/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:28:51 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/19 15:30:41 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	size_t	i;
	char	*memory;

	bytes = nmemb * size;
	if (size != 0 && ((bytes / size) != nmemb))
		return (NULL);
	memory = malloc (bytes);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
/*
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	n;
	
	i = 0;
	n = 5;
	char *maChaine1 = ft_calloc(n, sizeof(char));
	if (maChaine1 == NULL)
	{
		printf("ECHEC de ft_calloc");
		return (0);
	}
	char *maChaine2 = calloc(n, sizeof(char));
	if (maChaine2 == NULL) 
	{
		printf("ECHEC de calloc");
		return (0);
	}
	else
	{
		while (i < n)
		{
		printf("maChaine1 = %d\n", maChaine1[i]);
		printf("maChaine2 = %d\n", maChaine2[i]);
		i++;
		}
	}
	free(maChaine1);
	free(maChaine2);
	return (0);
}*/
