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

	if (!list || list->head->next == list->head)
		return ;
	first = list->head;
	second = list->head->next;
	last = list->head;
	if (second->next == list->head)
		list->head = list->head->next;
	else
	{
		while (last->next != list->head)
			last = last->next;
		list->head = list->head->next;
		first->next = second->next;
		second->next = first;
		last->next = list->head;
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
