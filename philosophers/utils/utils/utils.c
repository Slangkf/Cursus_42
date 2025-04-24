/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:56:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/09 15:56:47 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atol(const char *s)
{
	int		sign;
	long	result;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	result = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_display_state_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (ft_check_dead_flag(philo->table) == 0)
	{
		pthread_mutex_lock(&philo->table->start_time_lock);
		printf("%zu %d %s\n", (ft_get_current_time() - philo->table->start_time),
			philo->id, message);
		pthread_mutex_unlock(&philo->table->start_time_lock);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}
