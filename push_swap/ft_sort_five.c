/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:16:50 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/25 12:16:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_five(t_list *a)
{
	t_list	*b;
	int		smallest;

	b = ft_create_list();
	smallest = ft_find_smallest_index(a);
	find_best_path_tobig(a, smallest);
	ft_push_to_b(a, b);
	find_best_path_tobig(a, ft_find_smallest_index(a));
	ft_push_to_b(a, b);
	if (ft_check_order(a) == 1)
		ft_sort_three(a);
	ft_push_to_a(b, a);
	ft_push_to_a(b, a);
}
