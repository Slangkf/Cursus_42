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

#include "../header/push_swap.h"

t_node	*ft_find_biggest(t_list *list)
{
	t_node	*current;
	t_node	*biggest;

	current = list->head;
	biggest = list->head;
	while (current->next != list->head)
	{
		if (current->data > biggest->data)
			biggest = current;
		current = current->next;
	}
	if (current->data > biggest->data)
			biggest = current;
	return (biggest);
}
