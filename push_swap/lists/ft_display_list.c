/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:46:53 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:15:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_display_cloned_list(t_list *list)
{
	t_node	*current;

	if (!list->head)
		return ;
	current = list->head;
	ft_printf("\nB list : ");
	while (1)
	{
		ft_printf("%d (%d) -> ", current->data, current->index);
		current = current->next;
		if (current == list->head)
			break ;
	}
}

void	ft_display_list(t_list *list)
{
	t_node	*current;

	if (!list->head)
		return ;
	current = list->head;
	ft_printf("\nA list : ");
	while (1)
	{
		ft_printf("%d (%d) -> ", current->data, current->index);
		current = current->next;
		if (current == list->head)
			break ;
	}
}
