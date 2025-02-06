/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:40:58 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/05 09:43:17 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*ft_find_last(t_list *list)
{
	t_node	*last;

	last = list->head;
	while (last->next != list->head)
		last = last->next;
	return (last);
}
