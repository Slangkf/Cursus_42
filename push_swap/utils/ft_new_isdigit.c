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

#include "../push_swap.h"

int	ft_new_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 43 || str[i] == 45)
		{
			if (str[i + 1] == '\0')
				return (1);
			if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
				return (1);
			i++;
		}
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}
