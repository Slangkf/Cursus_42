/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:03:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/01 11:03:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_string_input(char **input)
{
	int	i;

	i = 0;
	while (input[i] != NULL)
	{
		if (ft_atol(input[i]) > INT_MAX || ft_atol(input[i]) < INT_MIN)
			return (1);
		if (ft_new_isdigit(input[i]) == 1)
			return (1);
		if (ft_new_isalpha(input[i]))
			return (1);
		if (ft_new_strchr(input[i], ' ') == 1)
			return (1);
		i++;
	}
	if (ft_check_double(input) == 1)
		return (1);
	return (0);
}

int	ft_check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		if (ft_new_isdigit(argv[i]) == 1)
			return (1);
		if (ft_new_isalpha(argv[i]))
			return (1);
		if (ft_new_strchr(argv[i], ' ') == 1)
			return (1);
		i++;
	}
	if (ft_check_double(argv) == 1)
		return (1);
	return (0);
}
