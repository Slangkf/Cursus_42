/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:03:49 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/14 15:03:50 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	count_moves_prev(t_list *list, int idx)
{
	t_node	*head;
	int		count;

	head = list->head;
	count = 0;
	while (head->next != list->head)
	{
		if (head->index == idx)
			break ;
		head = head->next;
		count++;
	}
	return (count);
}


static int	count_moves_next(t_list *list, int idx)
{
	t_node	*head;
	int		count;

	head = list->head;
	count = 0;
	while (head->next != list->head)
	{
		if (head->index == idx)
			break ;
		head = head->next;
		count++;
	}
	return (count);
}

int	ft_count_moves(t_list *list)
{
	int	idx;
	int	next;
	int	prev;

	idx = ft_find_biggest_index(list);
	next = count_moves_next(list, idx);
	prev = count_moves_prev(list, idx);
	if (next <= prev)
		return (next);
	else
		return (prev);
}
