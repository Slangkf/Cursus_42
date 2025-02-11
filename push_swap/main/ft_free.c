/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:11:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 17:11:19 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return ;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		list->head->data = 0;
		list->head = list->head->next;
	}
	if (list->head->next == tmp)
	{
		list->head->data = 0;
		list->head = list->head->next;
	}
	free(list);
}
