/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:03:30 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/01 10:46:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	separ_args(t_list *a, char **argv)
{
	int		j;
	int		count;
	char	**input;

	j = 0;
	count = ft_count_sub(argv[1], ' ');
	input = ft_split(argv[1], ' ');
	if (ft_check_string_input(input) == 1)
	{
		while (count--)
			free(input[count]);
		free(input);
		return (1);
	}
	while (input[j] != NULL)
	{
		ft_fill_list(a, ft_atoi(input[j]));
		j++;
	}
	while (count--)
		free(input[count]);
	free(input);
	return (0);
}

int	ft_init_list(t_list *a, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		if (separ_args(a, argv) == 1)
			return (1);
	}
	else if (argc > 2)
	{
		if (ft_check_input(argv) == 1)
			return (1);
		while (i < argc)
		{
			ft_fill_list(a, ft_atoi(argv[i]));
			i++;
		}
	}
	return (0);
}
