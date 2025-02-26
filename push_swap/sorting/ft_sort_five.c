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

static int	ft_best_ptbi_is_bottom(t_list *list, int smallest)
{
	t_node	*tail;
	int		i;

	tail = list->head->prev;
	i = 1;
	while (tail->index != smallest)
	{
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	ft_best_ptbi_is_top(t_list *list, int smallest)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 0;
	while (head->index != smallest)
	{
		head = head->next;
		i++;
	}
	return (i);
}

static void	find_best_path_tobig(t_list *list, int smallest)
{
	t_node	*head;
	int		top;
	int		bottom;

	top = ft_best_ptbi_is_top(list, smallest);
	bottom = ft_best_ptbi_is_bottom(list, smallest);
	head = list->head;
	if (top <= bottom)
	{
		while (head->index != smallest)
		{
			ft_rotate_a(list);
			head = list->head;
			if (head->index == smallest)
				break ;
		}
	}
	else if (top > bottom)
	{
		while (head->index != smallest)
		{
			ft_reverse_rotate_a(list);
			head = list->head;
			if (head->index == smallest)
				break ;
		}
	}
}

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
