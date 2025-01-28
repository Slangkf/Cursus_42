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
	int		i;
	char	**input = NULL;

	a = create_list();
	b = create_list();
	i = 1;
	if (argc == 1 || !(argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argc = ft_count_sub(argv[1], ' ');
		while (i < argc)
		{
			input[i] = *ft_split(argv[1], ' ');
			i++;
		}
		i = 1;
		while (i < argc)
		{
			ft_fill_list(a, argv[1]);
			i++;
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
	ft_printf("B liste after push : ");
	display_list(b);
	ft_printf("\n");
	return (0);
	}
	if (argc > 2)
	{
		while (i < argc)
			ft_fill_list(a, argv[i++]);
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
	ft_printf("B liste after push : ");
	display_list(b);
	ft_printf("\n");
	return (0);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = create_list();
	b = create_list();
	i = 1;
	if (argc == 1 || !(argv[1][0]))
		ft_printf("Erreur, veuillez entrer des arguments valides svp.\n");
	while (i < argc)
	{
		ft_fill_list(a, argv[i]);
		i++;
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
	ft_printf("B liste after push : ");
	display_list(b);
	ft_printf("\n");
	return (0);
}*/
