/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:06:13 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 17:18:35 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	reverse_rotate(t_list *list)
{
	t_node	*last;

	last = list->head->prev;
	list->head = last;
}

void	ft_reverse_rotate_a(t_list *a)
{
	if (!a || a->head->next == a->head)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_list *b)
{
	if (!b || b->head->next == b->head)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_both(t_list *a, t_list *b)
{
	if (!(a && b) || (a->head->next == a->head || b->head->next == b->head))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
