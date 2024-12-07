/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:27:42 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/07 10:02:48 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_p(unsigned long long nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_convert_p(nb / 16);
		i += ft_convert_p(nb % 16);
	}
	else
		i += ft_printchar(base[nb % 16]);
	return (i);
}

int	ft_printadress(unsigned long long nb)
{
	int		i;

	if (!nb)
		return (write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	return (i + ft_convert_p(nb));
}
