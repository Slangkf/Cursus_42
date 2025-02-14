/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:41:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/13 15:41:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_best_ptbi_is_bottom(t_list *list, int m)
{
	t_node	*tail;
	int		i;

	tail = ft_find_last(list);
	i = 0;
	while (tail->prev != list->head)
	{
		if (tail->index >= m)
			break ;
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	ft_best_ptbi_is_top(t_list *list, int m)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 0;
	while (head->next != list->head)
	{
		if (head->index >= m)
			break ;
		head = head->next;
		i++;
	}
	return (i);
}

int	ft_find_best_path_tobig(t_list *list, int m)
{
	int	top;
	int	bottom;

	top = ft_best_ptbi_is_top(list, m);
	bottom = ft_best_ptbi_is_bottom(list, m);
	if (top < bottom)
		return (0);
	else
		return (1);
}

static int	ft_best_ptsi_is_bottom(t_list *list, int m)
{
	t_node	*tail;
	int		i;

	tail = ft_find_last(list);
	i = 0;
	while (tail->prev != list->head)
	{
		if (tail->index <= m)
			break ;
		tail = tail->prev;
		i++;
	}
	return (i);
}

static int	ft_best_ptsi_is_top(t_list *list, int m)
{
	t_node	*head;
	int		i;

	head = list->head;
	i = 0;
	while (head->next != list->head)
	{
		if (head->index <= m)
			break ;
		head = head->next;
		i++;
	}
	return (i);
}

int	ft_find_best_path_tosma(t_list *list, int m)
{
	int	top;
	int	bottom;

	top = ft_best_ptsi_is_top(list, m);
	bottom = ft_best_ptsi_is_bottom(list, m);
	if (top < bottom)
		return (0);
	else
		return (1);
}
