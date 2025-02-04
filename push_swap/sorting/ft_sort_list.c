/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:48:51 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/03 17:48:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_list(t_list *a)
{
	int		i;
	t_node	*head;

	i = 1;
	head = a->head;
	while (head->next != a->head)
	{
		head = head->next;
		i++;
	}
	if (i == 2)
		ft_swap_a(a);
	else if (i == 3)
		ft_sort_three(a);
	else if (i == 4)
		ft_sort_four(a);
	else if (i == 5)
		ft_sort_five(a);
	//else
	//	ft_sort_more(a);
	return ;
}
