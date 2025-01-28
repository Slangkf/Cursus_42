/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/22 13:10:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//create structures
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*head;
}	t_list;

//create lists
t_list	*create_list(void);
void	ft_fill_list(t_list *list, char *argv);
void	display_list(t_list *list);

//instructions
void	ft_swap_a(t_list *a);
void	ft_swap_b(t_list *b);
void	ft_swap_both(t_list *a, t_list *b);

void	ft_push_to_a(t_list *b, t_list *a);
void	ft_push_to_b(t_list *a, t_list *b);

void	ft_rotate_a(t_list *a);
void	ft_rotate_b(t_list *b);
void	ft_rotate_both(t_list *a, t_list *b);

void	ft_reverse_rotate_a(t_list *a);
void	ft_reverse_rotate_b(t_list *b);
void	ft_reverse_rotate_both(t_list *a, t_list *b);

int		main(int argc, char **argv);

//utils
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t siz);

long	ft_atol(const char *s);

int		ft_printf(const char *format, ...);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printadress(unsigned long long nb);
int		ft_printhexa_low(unsigned int nb);
int		ft_printhexa_upp(unsigned int nb);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_count_sub(const char *s, char c);

#endif
