/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/07 18:07:14 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

//structs
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*head;
}	t_list;

//main
int		main(int argc, char **argv);

//lists
t_list	*ft_init_list(int argc, char **argv);
t_list	*ft_create_list(void);

void	ft_fill_list(t_list *list, char *argv);
void	ft_display_list(t_list *list);
void	ft_display_cloned_list(t_list *list);

//checks
int		ft_check_input(char **argv);

//sorting
void	ft_check_and_sort(t_list *a);
void	ft_sort_list(t_list *a);
void	ft_sort_three(t_list *a);
void	ft_sort_four(t_list *a);
void	ft_sort_more(t_list *a);

//instructions
void	ft_swap_a(t_list *a);
void	ft_swap_b(t_list *b);
void	ft_swap(t_list *list);
void	ft_swap_both(t_list *a, t_list *b);
void	ft_push_to_a(t_list *b, t_list *a);
void	ft_push_to_b(t_list *a, t_list *b);
void	ft_rotate_a(t_list *a);
void	ft_rotate_b(t_list *b);
void	ft_rotate_both(t_list *a, t_list *b);
void	ft_reverse_rotate_a(t_list *a);
void	ft_reverse_rotate_b(t_list *b);
void	ft_reverse_rotate_both(t_list *a, t_list *b);

//utils
t_node	*ft_find_biggest(t_list *list);
t_node	*ft_find_smallest(t_list *list);
t_node	*ft_find_last(t_list *list);

long	ft_atol(const char *s);

void	ft_clone_list(t_list *list);
void	ft_index_list(t_list *list);
void	ft_index_a(t_list *a);

int		ft_find_pos_small(t_node *smallest, t_list *list);
int		ft_length_list(t_list *list);
int		ft_find_median_list(t_list *list);
int		ft_new_strchr(const char *s, int c);
int		ft_new_isdigit(char **argv);
int		ft_new_isalpha(char **argv);
int		ft_check_order(t_list *list);
int		ft_check_double(char **argv);
int		ft_length_list(t_list *list);
#endif
