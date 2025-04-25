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

void	ft_free_all(t_list *list)
{
	ft_free_list(list);
	free(list);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (ft_new_isalpha(argv[1]) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc < 2 || (argc == 2 && ft_count_sub(argv[1], ' ') <= 1))
		return (1);
	if (argv[1][0])
	{
		a = ft_create_list();
		if (ft_init_list(a, argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			ft_free_all(a);
			return (1);
		}
		if (ft_length_list(a) >= 4)
			ft_clone_a(a);
		ft_check_and_sort(a);
		ft_display_list(a);
		ft_free_all(a);
	}
	return (0);
}
