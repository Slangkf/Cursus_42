/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:02:39 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:26:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_check_and_sort(t_list *a)
{
	t_node	*head;

	if (a->head->next == a->head)
		return ;
	head = a->head;
	while (head->next != a->head)
	{
		if (head->data < head->next->data)
			head = head->next;
		else
		{
			ft_sort_list(a);
			break ;
		}
	}
	return ;
}
