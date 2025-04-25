/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_biggest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:57:12 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/05 15:57:14 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_biggest_index(t_list *list)
{
	t_node	*current;
	int		index;

	current = list->head;
	index = list->head->index;
	while (current->next != list->head)
	{
		if (index < current->index)
			index = current->index;
		current = current->next;
	}
	if (current->next == list->head)
	{
		if (index < current->index)
			index = current->index;
	}
	return (index);
}
