/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:01:48 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/23 11:28:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_rotate(t_list *list)
{
	t_node	*last;

	last = list->head;
	last = last->next;
	list->head = last;
}

void	ft_rotate_a(t_list *a)
{
	if (!a || a->head->next == a->head)
		return ;
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list *b)
{
	if (!b || b->head->next == b->head)
		return ;
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rotate_both(t_list *a, t_list *b)
{
	if (!(a && b) || (a->head->next == a->head && b->head->next == b->head))
		return ;
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
