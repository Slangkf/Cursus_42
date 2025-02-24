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

static void	make_chunks_and_pb(t_list *a, t_list *b, int m, int mbis)
{
	if (a->head->index <= m)
	{	
		if (a->head->index <= mbis)
		{	
			ft_push_to_b(a, b);
			ft_rotate_b(b);
		}
		else if (a->head->index > mbis || !b->head->data)
			ft_push_to_b(a, b);
	}
	else if (a->head->index > m)
	{
		if (ft_compare_list_to_m(a, m) == 1)
		{
			if (ft_find_best_path_tosma(a, m) == 0)
				ft_rotate_a(a);
			else if (ft_find_best_path_tosma(a, m) == 1)
				ft_reverse_rotate_a(a);
		}
	}	
}

static	void	empty_list_a(t_list *a, t_list *b)
{
	int 		m;
	int		mbis;

	m = ((ft_find_biggest_index(a) + ft_find_smallest_index(a)) / 3);
	mbis = ((m + ft_find_smallest_index(a)) / 2);
	while (ft_length_list(a) > 2)
	{
		while (ft_compare_list_to_m(a, m) != 0)
			make_chunks_and_pb(a, b, m, mbis);
		m = ((ft_find_biggest_index(a) + ft_find_smallest_index(a)) / 2);
		mbis = ((m + ft_find_smallest_index(a)) / 2);
	}
	if (ft_length_list(a) <= 2)
	{
		ft_push_to_b(a, b);
		ft_push_to_b(a, b);
	}
}

static	void	check_and_pa(t_list *b, t_list *a, int biggest)
{
	ft_find_best_path_tobig(b, biggest);
	ft_push_to_a(b, a);
}

static	void	fillout_list_a(t_list *a, t_list *b)
{
	t_node	*head_b;
	int		biggest;

	head_b = b->head;
	biggest = ft_find_biggest_index(b);
	while (ft_length_list(b) != 0)
	{
		head_b = b->head;
		biggest = ft_find_biggest_index(b);
		if (head_b->index == biggest)
			ft_push_to_a(b, a);
		else if (head_b->index != biggest)
			check_and_pa(b, a, biggest);
	}
}

void	ft_sort_more(t_list *a)
{
	t_list	*b;

	b = ft_create_list();
	empty_list_a(a, b);
	fillout_list_a(a, b);
	//ft_display_list(a);
	//ft_display_cloned_list(b);
}
