/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:51 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/31 12:25:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atol(argv[i]) - ft_atol(argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double_string(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atol(argv[i]) - ft_atol(argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
