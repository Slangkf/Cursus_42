/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:51 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/31 12:25:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_double(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			k = 0;
			while (argv[j][k] == 48 && argv[j][k + 1] != '\0')
			{
				k++;
				if (argv[j][k + 1] == '\0')
					argv[j] = &argv[j][k];
			}
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
