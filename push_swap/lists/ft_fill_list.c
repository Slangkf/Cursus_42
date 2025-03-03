/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:28:47 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:16:28 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_fill_list(t_list *list, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(data);
	if (!list->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		list->head = new_node;
	}
	else
	{
		current = list->head;
		while (current->next != list->head)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
		new_node->next = list->head;
		list->head->prev = new_node;
	}
}
