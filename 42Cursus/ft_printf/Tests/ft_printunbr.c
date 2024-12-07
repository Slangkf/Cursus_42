/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:32:34 by tclouet           #+#    #+#             */
/*   Updated: 2024/11/29 10:32:36 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_printunbr(n / 10);
	}
		i += ft_printchar((n % 10) + '0');
	return (i);
}
