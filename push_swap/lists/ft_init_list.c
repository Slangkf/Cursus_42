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

static t_list	*ft_separ_args(char **argv)
{
	t_list	*a;
	char	**input;
	int		i;

	a = create_list();
	input = ft_split(argv[1], 32);
	i = 0;
	while (input[i])
	{
		if (ft_check_input(&input[i]) == 1)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		ft_fill_list(a, input[i]);
		i++;
	}
	free(input);
	return (a);
}

t_list	*ft_init_list(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = create_list();
	i = 1;
	if (argc == 2)
		a = ft_separ_args(argv);
	else
	{
		while (i < argc)
		{
			if (ft_check_input(&argv[i]) == 1)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			ft_fill_list(a, argv[i]);
			i++;
		}
	}
	return (a);
}
