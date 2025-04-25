/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:13:20 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:18:24 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	remove_node_first_list(t_list *list)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!list || !list->head)
		return ;
	first = list->head;
	if (first->next == first)
		list->head = NULL;
	else
	{
		second = first->next;
		last = first->prev;
		last->next = second;
		second->prev = last;
		list->head = second;
	}
}

static void	add_to_second_list(t_list *list, t_node *add)
{
	t_node	*first;
	t_node	*last;

	if (!list)
		return ;
	if (list->head == NULL)
	{
		add->next = add;
		add->prev = add;
		list->head = add;
	}
	else
	{
		first = list->head;
		last = list->head;
		while (last->next != list->head)
			last = last->next;
		add->next = first;
		add->prev = last;
		first->prev = add;
		last->next = add;
		list->head = add;
	}
}

void	ft_push_to_a(t_list *b, t_list *a)
{
	t_node	*first;

	if (!b || b->head == NULL)
		return ;
	first = b->head;
	remove_node_first_list(b);
	add_to_second_list(a, first);
	write(1, "pa\n", 3);
}

void	ft_push_to_b(t_list *a, t_list *b)
{
	t_node	*first;

	if (!a || a->head == NULL)
		return ;
	first = a->head;
	remove_node_first_list(a);
	add_to_second_list(b, first);
	write(1, "pb\n", 3);
}
