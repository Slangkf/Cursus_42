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

static void	sort_list(t_list *a)
{
	int		i;

	i = ft_length_list(a);
	if (i == 2)
		ft_swap_a(a);
	else if (i == 3)
		ft_sort_three(a);
	else if (i > 3)
		write(1,"ERREUR\n", 7);
	else
		return ;
}

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
	while (ft_length_list(a) > 3)
	{
		while (ft_compare_list_to_m(a, m) != 0)
			make_chunks_and_pb(a, b, m, mbis);
		m = ((ft_find_biggest_index(a) + ft_find_smallest_index(a)) / 2);
		mbis = ((m + ft_find_smallest_index(a)) / 2);
	}
}

static	void	check_and_pa(t_list *b, t_list *a)
{
	int	biggest;
	int	moves;

	biggest = ft_find_biggest_index(b);
	moves = ft_count_moves(b);
	if (b->head->index == biggest)
		ft_push_to_a(b, a);
	else if (b->head->index != biggest)
	{
		if (moves > 2)
		{
			ft_push_to_a(b, a);
			ft_rotate_a(a);
		}
		else if (moves <= 2)
		{
			if (ft_find_best_path_tobig(a, biggest) == 0)
				ft_rotate_b(b);
			else if (ft_find_best_path_tobig(a, biggest) == 1)
				ft_reverse_rotate_b(b);
		}
	}
}

static	void	fillout_list_a(t_list *a, t_list *b)
{
	while (ft_length_list(b) != 1)
		check_and_pa(b, a);
}

void	ft_sort_more(t_list *a)
{
	t_list	*b;

	b = ft_create_list();
	empty_list_a(a, b);
	if (ft_check_order(a) == 1)
		sort_list(a);
	fillout_list_a(a, b);
	//ft_display_list(a);
	//ft_display_cloned_list(b);
}
