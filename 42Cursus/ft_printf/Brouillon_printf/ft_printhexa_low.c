/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:55:51 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/07 10:02:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_low(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_printhexa_low(nb / 16);
		i += ft_printhexa_low(nb % 16);
	}
	else
		i += ft_printchar(base[nb % 16]);
	return (i);
}
