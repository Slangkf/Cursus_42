/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:17 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/07 10:03:40 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printadress(unsigned long long nb);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printhexa_low(unsigned int nb);
int		ft_printhexa_upp(unsigned int nb);
char	*ft_strchr(const char *s, int c);
#endif
