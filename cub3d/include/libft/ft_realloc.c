/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:03:02 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/07 13:03:03 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t new_size)
{
	char	*result;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	result = malloc(new_size);
	if (!result)
		return ((free(ptr), NULL));
	if (new_size > ptr_size)
		result = ft_memcpy(result, ptr, ptr_size);
	else if (new_size < ptr_size)
		result = ft_memcpy(result, ptr, new_size);
	return (free(ptr), result);
}
