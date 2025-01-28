/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 16:51:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_count_sub(const char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (i);
}
