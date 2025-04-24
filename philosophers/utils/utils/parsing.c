/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:33:26 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/09 15:33:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_values(char **argv)
{
	int	i;

	if (ft_atol(argv[1]) <= 0 || ft_atol(argv[1]) > 200)
		return (1);
	i = 2;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

static int	new_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (new_is_digit(argv) == 1)
		return (1);
	if (check_values(argv) == 1)
		return (1);
	else
		return (0);
}
