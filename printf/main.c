/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:09:17 by tclouet           #+#    #+#             */
/*   Updated: 2024/12/06 10:09:19 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	ft_printf("Imprime char: %c et string: %s\n", 'c', "Hello !");
	printf("Imprime char: %c et string: %s\n", 'c', "Hello !");
	ft_printf("Imprime l'adresse de 'ft_printf' : %p\n", &ft_printf);
	printf("Imprime l'adresse de 'ft_printf' : %p\n", &ft_printf);
	ft_printf("Imprime les entiers signes: %d et %i\n", -4, -2);
	printf("Imprime les entiers signes: %d et %i\n", -4, -2);
	ft_printf("Imprime l'entier non signe: %u\n", 7);
	printf("Imprime l'entier non signe: %u\n", 7);
	ft_printf("Imprime les hexa minus: %x et majus: %X\n", 158020, 158020);
	printf("Imprime les hexa minus: %x et majus: %X\n", 158020, 158020);
	return (0);
}
