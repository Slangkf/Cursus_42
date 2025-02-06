/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:50:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/05 15:50:08 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_find_median_list(t_list *list)
{
	int	i;

	i = (ft_length_list(list));
	if (i % 2 == 1)
		i = ((ft_length_list(list) * 2 + 2) / 4);
	if (i % 2 == 0)
		i = (ft_length_list(list) / 2);
	return (i);
}
