/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:26:46 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/28 11:37:44 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	past_index_to_a(t_list *c, t_list *a)
{
	t_node	*head_a;
	t_node	*head_c;

	head_a = a->head;
	head_c = c->head;
	while (head_a->index == 0)
	{
		if (head_c->data == head_a->data)
		{
			head_a->index = head_c->index;
			head_a = head_a->next;
			head_c = head_c->next;
		}
		else
			head_c = head_c->next;
	}
}

static void	sort_clone(t_list *c)
{
	t_node	*head;
	int		tmp;

	head = c->head;
	while (head->next != c->head)
	{
		if (head->data > head->next->data)
		{
			tmp = head->data;
			head->data = head->next->data;
			head->next->data = tmp;
			head = c->head;
		}
		else
			head = head->next;
	}
}

static void	fill_clone(t_list *c, t_node *head_a)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->data = head_a->data;
	if (!c->head)
	{
		new_node->next = new_node;
		c->head = new_node;
	}
	else
	{
		current = c->head;
		while (current->next != c->head)
			current = current->next;
		current->next = new_node;
		new_node->next = c->head;
	}
}

static t_list	*past_list(t_list *a)
{
	t_list	*c;
	t_node	*head_a;

	c = ft_create_list();
	head_a = a->head;
	while (head_a->next != a->head)
	{
		fill_clone(c, head_a);
		head_a = head_a->next;
	}
	if (head_a->next == a->head)
		fill_clone(c, head_a);
	return (c);
}

void	ft_clone_a(t_list *a)
{
	t_list	*c;

	c = past_list(a);
	sort_clone(c);
	ft_index_list_a(a);
	ft_index_list_c(c);
	past_index_to_a(c, a);
	ft_free_list(c);
	free(c);
}
