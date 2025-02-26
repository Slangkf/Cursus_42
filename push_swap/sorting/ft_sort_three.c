/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:41:08 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 09:41:10 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_three(t_list *a)
{
	int	one;
	int	two;
	int	three;

	one = a->head->data;
	two = a->head->next->data;
	three = a->head->next->next->data;
	if (one > two && two < three && three > one)
		ft_swap_a(a);
	else if (one < two && two > three && three < one)
		ft_reverse_rotate_a(a);
	else if (one > two && two < three && three < one)
		ft_rotate_a(a);
	else if (one < two && two > three && three > one)
	{
		ft_reverse_rotate_a(a);
		ft_swap_a(a);
	}
	else if (one > two && two > three && three < one)
	{
		ft_swap_a(a);
		ft_reverse_rotate_a(a);
	}
}
