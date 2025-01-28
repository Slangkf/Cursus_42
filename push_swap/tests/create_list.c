/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:45:24 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 12:51:49 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->head = NULL;
	return (new_list);
}
