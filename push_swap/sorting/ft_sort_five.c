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

#include "../push_swap.h"

static int	best_path_isbot(t_list *list, int smallest)
{
	t_node	*tail;
	int		i;

	tail = list->head->prev;
	i = 0;
	while (tail->index != smallest)
	{
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	best_path_istop(t_list *list, int smallest)
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

static void	bring_up_smallest(t_list *list, int smallest, int top, int bottom)
{
	t_node	*head;

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

static void	find_best_path_tosma(t_list *list, int smallest)
{
	int		top;
	int		bottom;

	top = best_path_istop(list, smallest);
	bottom = best_path_isbot(list, smallest);
	bring_up_smallest(list, smallest, top, bottom);
}

void	ft_sort_five(t_list *a)
{
	t_list	*b;
	int		smallest;

	b = ft_create_list();
	smallest = ft_find_smallest_index(a);
	find_best_path_tosma(a, smallest);
	ft_push_to_b(a, b);
	find_best_path_tosma(a, ft_find_smallest_index(a));
	ft_push_to_b(a, b);
	if (ft_check_order(a) == 1)
		ft_sort_three(a);
	ft_push_to_a(b, a);
	ft_push_to_a(b, a);
	ft_free_list(b);
	free(b);
}
