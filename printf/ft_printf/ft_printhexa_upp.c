/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:56:03 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/07 10:03:13 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printhexa_upp(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_printhexa_upp(nb / 16);
	i += ft_printchar(base[nb % 16]);
	return (i);
}
