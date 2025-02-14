/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_list_to_m.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/12 15:31:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_compare_list_to_m(t_list *a, int m)
{
	t_node	*head;

	head = a->head;
	while (head->next != a->head)
	{
		if (head->index <= m)
			return (1);
		else
			head = head->next;
	}
	if (head->next == a->head)
	{
		if (head->index <= m)
			return (1);
	}
	return (0); 
}
