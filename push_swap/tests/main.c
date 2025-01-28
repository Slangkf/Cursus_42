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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = create_list();
	b = create_list();
	i = 1;
	if (argc == 1 || !(argv[1][0]))
		printf("Erreur, veuillez entrer des arguments valides svp.\n");
	if (argc == 2)
		ft_split(argv[1], ' ');
	while (i < argc)
	{
		ft_fill_list(a, argv[i]);
		i++;
	}
	printf("A list before : ");
	display_list(a);
	printf("\n");
	printf("B list before : ");
	display_list(b);
	printf("\n");
	ft_push_to_b(a, b);
	printf("\n");
	printf("A list after push : ");
	display_list(a);
	printf("\n");
	printf("B liste after push : ");
	display_list(b);
	printf("\n");
	return (0);
}
