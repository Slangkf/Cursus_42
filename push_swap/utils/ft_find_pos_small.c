/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:51:11 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/05 15:51:13 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_find_pos_small(int smallest, t_list *list)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 1;
	while (head->index != smallest)
	{
		head = head->next;
		i++;
	}
	return (i);
}
