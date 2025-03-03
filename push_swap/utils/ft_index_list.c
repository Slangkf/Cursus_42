/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:38:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 12:38:05 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_index_list_a(t_list *list)
{
	t_node	*head;

	head = list->head;
	while (head->next != list->head)
	{
		head->index = 0;
		head = head->next;
	}
	if (head->next == list->head)
		head->index = 0;
}

void	ft_index_list_c(t_list *list)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 1;
	while (head->next != list->head)
	{
		head->index = i++;
		head = head->next;
	}
	if (head->next == list->head)
		head->index = i;
}
