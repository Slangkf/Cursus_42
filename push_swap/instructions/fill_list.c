/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:28:47 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 12:51:58 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_fill_list(t_list *list, char *argv)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = ft_atol(argv);
	if (!list->head)
	{
		new_node->next = new_node;
		list->head = new_node;
	}
	else
	{
		current = list->head;
		while (current->next != list->head)
			current = current->next;
		current->next = new_node;
		new_node->next = list->head;
		list->head = new_node;
	}
}
