/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:42:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/28 12:42:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc < 2)
		return (1);
	a = ft_init_list(argc, argv);
	ft_check_and_sort(a);
	ft_display_list(a);
	free(a);
	return (0);
}
