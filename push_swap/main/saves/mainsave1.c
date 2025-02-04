/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:42:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 12:42:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**input;
	int		i;

	a = create_list();
	b = create_list();
	i = 1;
	input = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input[1])
			return (ft_printf("Error\n"));	
		while (*input)
		{
			if (ft_new_isdigit(*input) == -1)
				return (ft_printf("Error\n"));
			if (ft_check_double(input) == -1)
				return (ft_printf("Error\n"));
			ft_fill_list(a, *input);
			input++;
		}
	}
	if (argc > 2)
	{
		while (i < argc)
		{
			if (ft_new_strchr(argv[i], ' ') == -1)
				return (ft_printf("Error\n"));
			if (ft_new_isdigit(argv[i]) == -1)
				return (ft_printf("Error\n"));
			if (ft_check_double_bis(argv) == -1)
				return (ft_printf("Error\n"));
			ft_fill_list(a, argv[i]);
			i++;
		}
	}
	ft_printf("A list before : ");
	display_list(a);
	ft_printf("\n");
	ft_printf("B list before : ");
	display_list(b);
	ft_printf("\n");
	ft_push_to_b(a, b);
	ft_printf("\n");
	ft_printf("A list after push : ");
	display_list(a);
	ft_printf("\n");
	ft_printf("B list after push : ");
	display_list(b);
	ft_printf("\n");
	return (0);
}
