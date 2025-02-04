/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:08:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/04 15:08:05 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_five(t_list *a)
{
	t_list	*b;

	b = create_list();
	a->head = ft_find_smallest(a);
	ft_push_to_b(a, b);
	a->head = ft_find_smallest(a);
	ft_push_to_b(a, b);
	ft_sort_three(a);
	ft_push_to_a(b, a);
	ft_push_to_a(b, a);
	free(b);
}
