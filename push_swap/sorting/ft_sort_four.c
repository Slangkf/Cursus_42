/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:51:19 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 12:51:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	check_and_sort(int m, t_list *a, t_list *b)
{
	t_node	*smallest;
	t_node	*last;
	int		p;

	smallest = ft_find_smallest(a);
	last = ft_find_last(a);
	p = ft_find_pos_small(smallest, a);
	if (p <= m)
	{
		if (smallest != a->head)
			ft_swap_a(a);
		if (smallest == a->head && (ft_check_order(a) == 1))
			ft_push_to_b(a, b);
	}
	if (p > m)
	{
		while (smallest != a->head)
			ft_reverse_rotate_a(a);
		if (smallest == a->head && (ft_check_order(a) == 1))
			ft_push_to_b(a, b);
	}
}

void	ft_sort_four(t_list *a)
{
	t_list	*b;
	int		m;

	b = ft_create_list();
	m = ft_find_median_list(a);
	check_and_sort(m, a, b);
	if (ft_check_order(a) == 1)
	{
		ft_sort_three(a);
		ft_push_to_a(b, a);
	}
}
