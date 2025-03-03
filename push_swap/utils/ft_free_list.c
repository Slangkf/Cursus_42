/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:40:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/28 11:40:23 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*void	ft_free_list(t_list *list)
{
	t_node	*current;
	t_node	*tmp;

	if (!list || !list->head)
		return ;
	current = list->head;
	if (list->head->next == list->head)
	{
		free(list->head);
		list->head = NULL;
		free(list);
		return ;
	}
	while (current)
	{
		tmp = current->next;
		free(current);
		if (tmp == list->head)
			break ;
		current = tmp;
	}
	list->head = NULL;
	free(list);
}*/

void	ft_free_list(t_list *list)
{
	t_node	*current;
	t_node	*tmp;

	if (!list->head)
		return ;
	current = list->head;
	tmp = NULL;
	while (current->next != list->head)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	if (current != list->head)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	list->head = NULL;
}
