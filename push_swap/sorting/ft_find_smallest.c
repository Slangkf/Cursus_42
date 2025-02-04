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

#include "../header/push_swap.h"

t_node	*ft_find_smallest(t_list *list)
{
	t_node	*current;
	t_node	*smallest;

	current = list->head;
	smallest = list->head;
	while (current->next != list->head)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
	}
	if (current->data < smallest->data)
			smallest = current;
	return(smallest);
}
