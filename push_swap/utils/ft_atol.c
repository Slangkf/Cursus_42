/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:53:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/22 10:23:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	ft_atol(const char *s)
{
	int		sign;
	long	result;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	result = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
	{
		ft_printf("Error\n");
		exit (0);
	}
	return (result * sign);
}
