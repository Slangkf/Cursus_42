/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bottom_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:53:34 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/12 14:53:36 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_bottom_list(t_list *a, int m)
{
	t_node	*tail;

	tail = a->head->prev;
	if (tail->index < m)
		return (0);
	else
		return (1);
}
