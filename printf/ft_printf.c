/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:03:22 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/04 12:03:29 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (format == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_printadress(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_printunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_printhexa_low(va_arg(args, unsigned int));
	else if (format == 'X')
		i += ft_printhexa_upp(va_arg(args, unsigned int));
	else if (format == '%')
		return (ft_printchar('%'));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				i += ft_check_type(*format, args);
		}
		else
			i += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
