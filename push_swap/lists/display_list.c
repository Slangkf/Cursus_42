/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:46:53 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 12:46:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	display_list(t_list *list)
{
	t_node	*current;

	if (!list->head)
		return ;
	current = list->head;
	while (1)
	{
		ft_printf("%d -> ", current->data);
		current = current->next;
		if (current == list->head)
			break ;
	}
}
