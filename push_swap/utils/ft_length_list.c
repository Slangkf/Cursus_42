/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:25:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/05 15:25:03 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_length_list(t_list *list)
{
	t_node	*head;
	int		i;

	if (!list->head)
		return (0);
	head = list->head;
	i = 1;
	while (head->next != list->head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
