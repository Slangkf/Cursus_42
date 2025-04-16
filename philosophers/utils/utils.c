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

size_t	ft_get_start_time(void)
{
	struct timeval	simu_start;
	size_t			seconds;
	size_t			microseconds;
	size_t			milliseconds;

	gettimeofday(&simu_start, NULL);
	seconds = simu_start.tv_sec;
	microseconds = simu_start.tv_usec;
	return (milliseconds = (simu_start.tv_sec * 1000)
		+ (simu_start.tv_usec / 1000));
}

size_t	ft_get_step_time(t_philo *philo)
{
	struct timeval	timestamp;
	size_t		time;
	size_t		step_timestamp;

	gettimeofday(&timestamp, NULL);
	time = (timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000);
	step_timestamp = time - philo->table->start_time;
	return (step_timestamp);
}

void	ft_display_state_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->access_to_mealstarget);
	pthread_mutex_lock(&philo->table->access_to_statemessage);
	printf("[%zu ms] %d %s\n", ft_get_step_time(philo), philo->id, message);
	pthread_mutex_unlock(&philo->table->access_to_statemessage);
	pthread_mutex_unlock(&philo->table->access_to_mealstarget);
}
