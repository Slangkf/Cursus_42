/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_isalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:35 by tclouet           #+#    #+#             */
/*   Updated: 2025/01/29 16:11:53 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_new_isalpha(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			return (1);
		if (str[i] >= 97 && str[i] <= 122)
			return (1);
		i++;
	}
	return (0);
}
