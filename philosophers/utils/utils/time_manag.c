/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:54:10 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/17 11:55:35 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	timestamp;
	size_t			seconds;
	size_t			microseconds;
	size_t			current_time;

	gettimeofday(&timestamp, NULL);
	seconds = timestamp.tv_sec;
	microseconds = timestamp.tv_usec;
	current_time = seconds * 1000 + microseconds / 1000;
	return (current_time);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < milliseconds)
		usleep(500);
}

void	ft_init_start_time(t_philo *philo, t_program *table)
{
	int		i;
	size_t	time;

	i = 0;
	time = ft_get_current_time();
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&philo->table->start_time_lock);
		philo[i].last_meal = time;
		pthread_mutex_unlock(&philo->table->start_time_lock);
		i++;
	}
	pthread_mutex_lock(&table->start_time_lock);
	table->start_time = time;
	pthread_mutex_unlock(&table->start_time_lock);
}
