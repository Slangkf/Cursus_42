/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:32:22 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 16:32:23 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	check_and_sort(int m, t_list *a, t_list *b)
{
	t_node	*head_a;
	t_node	*head_b;
	int		count;

	head_a = a->head;
	head_b = b->head;
	count = 0;
	while (count != m)
	{
		if (a->head->index < m)
		{
			ft_push_to_b(a, b);
			count++;
		}
		else if (a->head->index >= m)
		{
			while (head_a->next != a->head)
				head_a = head_a->next;
			if (head_a->index < m)
			{
				ft_reverse_rotate_a(a);
				ft_push_to_b(a, b);
				count++;
			}
			else
			{
				ft_rotate_a(a);
				head_a = head_a->next;
			}
		}
	}
}

void	ft_sort_more(t_list *a)
{
	t_list	*b;
	int		m;

	b = ft_create_list();
	ft_index_a(a);
	m = ft_find_median_list(a);
	check_and_sort(m, a, b);
}
