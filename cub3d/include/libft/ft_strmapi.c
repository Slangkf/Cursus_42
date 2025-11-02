/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:36:17 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/28 09:36:19 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	result = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*

#include <stdlib.h>
#include <stdio.h>

static char	ft_change(unsigned int i, char c)
{
	if (i % 2 == 1)
		return (ft_toupper(c));
	else
		return (c);
}

static char	ft_change(unsigned int i, char c)
{
	(void) i;
		return (ft_toupper(c));
}

int	main(void)
{
	char	*result;
	
	result = ft_strmapi("Hello, World !", ft_change);
	printf("Nouvelle string: %s\n", result);
	return (0);
}*/
