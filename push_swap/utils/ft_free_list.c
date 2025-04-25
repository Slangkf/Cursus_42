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

#include "../push_swap.h"

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
