/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_path_tosma.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:01:45 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/26 13:01:49 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	best_path_isbot(t_list *list, int m)
{
	t_node	*tail;
	int		i;

	tail = list->head->prev;
	i = 0;
	while (tail->prev != list->head)
	{
		if (tail->index <= m)
			break ;
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	best_path_istop(t_list *list, int m)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 0;
	while (head->next != list->head)
	{
		if (head->index <= m)
			break ;
		head = head->next;
		i++;
	}
	return (i);
}

int	ft_find_best_path_tosma(t_list *list, int m)
{
	int	top;
	int	bottom;

	top = best_path_istop(list, m);
	bottom = best_path_isbot(list, m);
	if (top < bottom)
		return (0);
	else
		return (1);
}
