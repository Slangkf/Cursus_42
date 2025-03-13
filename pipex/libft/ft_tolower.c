/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:34:00 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/15 10:34:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	tab[] = {'H', 'e', 'l', 'l', 'o', '!'};
	int	i;
	i = 0;
	while (tab[i] != '\0')
	{
		printf("%c", ft_tolower(tab[i]));
		i++;
	}
	return (0);
}*/
