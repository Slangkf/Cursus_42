/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 13:03:28 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_smallest_index(t_list *list)
{
	t_node	*current;
	int		index;

	current = list->head;
	index = list->head->index;
	while (current->next != list->head)
	{
		if (index > current->index)
			index = current->index;
		current = current->next;
	}
	if (current->next == list->head)
	{
		if (index > current->index)
			index = current->index;
	}
	return (index);
}
