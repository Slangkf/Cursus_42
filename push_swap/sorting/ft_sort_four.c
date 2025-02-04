/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:51:19 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 12:51:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_four(t_list *a)
{
	t_list	*b;

	b = create_list();
	a->head = ft_find_smallest(a);
	ft_push_to_b(a, b);
	ft_sort_three(a);
	ft_push_to_a(b, a);
	free(b);
}
