/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:31:32 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:18:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap(t_list *list)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	second = list->head->next;
	if (!list || list->head->next == list->head)
		return ;
	if (second->next == list->head)
		list->head = second;
	else
	{
		first = list->head;
		last = list->head->prev;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		list->head = second;
	}
	return ;
}

void	ft_swap_a(t_list *a)
{
	if (!a || a->head->next == a->head)
		return ;
	ft_swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_list *b)
{
	if (!b || b->head->next == b->head)
		return ;
	ft_swap(b);
	write(1, "sb\n", 3);
	return ;
}

void	ft_swap_both(t_list *a, t_list *b)
{
	if (!(a && b) || (a->head->next == a->head && b->head->next == b->head))
		return ;
	ft_swap(a);
	ft_swap(b);
	write (1, "ss\n", 3);
	return ;
}
