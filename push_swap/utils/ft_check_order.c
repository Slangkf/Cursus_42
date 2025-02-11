/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:27:24 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:27:29 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_order(t_list *list)
{
	t_node	*head;

	head = list->head;
	while (head->next != list->head)
	{
		if (head->data < head->next->data)
			head = head->next;
		else
			return (1);
	}
	return (0);
}
