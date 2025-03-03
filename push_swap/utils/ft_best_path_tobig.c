/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_path_tobig.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:49:47 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/26 13:07:40 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	best_path_isbot(t_list *list, int biggest)
{
	t_node	*tail;
	int		i;

	tail = list->head->prev;
	i = 0;
	while (tail->index != biggest)
	{
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	best_path_istop(t_list *list, int biggest)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 0;
	while (head->index != biggest)
	{
		head = head->next;
		i++;
	}
	return (i);
}

static void	bring_up_biggest(t_list *list, int biggest, int top, int bottom)
{
	t_node	*head;

	head = list->head;
	if (top <= bottom)
	{
		while (head->index != biggest)
		{
			ft_rotate_b(list);
			head = list->head;
			if (head->index == biggest)
				break ;
		}
	}
	else if (top > bottom)
	{
		while (head->index != biggest)
		{
			ft_reverse_rotate_b(list);
			head = list->head;
			if (head->index == biggest)
				break ;
		}
	}
}

void	ft_find_best_path_tobig(t_list *list, int biggest)
{
	int		top;
	int		bottom;

	top = best_path_istop(list, biggest);
	bottom = best_path_isbot(list, biggest);
	bring_up_biggest(list, biggest, top, bottom);
}
