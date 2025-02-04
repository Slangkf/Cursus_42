/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:03:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/02/01 11:03:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_input(char **argv)
{
	if (ft_check_double(argv) == 1)
		return (1);
	if (ft_new_isalpha(argv) == 1)
		return (1);
	if (ft_new_isdigit(argv) == 1)
		return (1);
	if (ft_new_strchr(*argv, 32) == 1)
		return (1);
	return (0);
}
