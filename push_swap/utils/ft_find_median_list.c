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

#include "../push_swap.h"

int	ft_find_median_list(t_list *list)
{
	int	median;

	median = (ft_find_biggest_index(list) + ft_find_smallest_index(list)) / 2;
	return (median);
}
