/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:37 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/29 15:43:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_new_isdigit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == 43 || argv[i][j] == 45)
			{
				if (argv[i][j + 1] == '\0')
					return (1);
				if (!(argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
