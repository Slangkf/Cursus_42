/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:01:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/15 15:01:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meal_lock);
	if (philo->table->meals_target != -1 && philo->table->satiates
		== philo->table->nb_philo)
	{
		pthread_mutex_unlock(&philo->table->meal_lock);
		pthread_mutex_lock(&philo->table->deadflag_lock);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(&philo->table->deadflag_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->meal_lock);
	return (0);
}

static void	display_death_message(t_philo *philo, long timestamp)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("\033[31m%zu %d died\033[0m\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->table->print_lock);
}

static int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->start_time_lock);
	if (ft_get_current_time() - philo->last_meal > philo->table->time_todie)
	{
		pthread_mutex_unlock(&philo->table->start_time_lock);
		pthread_mutex_lock(&philo->table->deadflag_lock);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(&philo->table->deadflag_lock);
		display_death_message(philo, (ft_get_current_time()
				- philo->table->start_time));
		return (1);
	}
	pthread_mutex_unlock(&philo->table->start_time_lock);
	return (0);
}

int	ft_check_dead_flag(t_program *table)
{
	pthread_mutex_lock(&table->deadflag_lock);
	if (table->dead_flag == 1)
	{
		pthread_mutex_unlock(&table->deadflag_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->deadflag_lock);
	return (0);
}

void	ft_start_monitoring(t_philo *philo)
{
	int	i;

	ft_usleep(10);
	while (ft_check_dead_flag(philo->table) == 0)
	{
		i = 0;
		while (i < philo->table->nb_philo)
		{
			if (check_death(&philo[i]) == 1)
				break ;
			if (check_meals(&philo[i]) == 1)
				break ;
			i++;
		}
		ft_usleep(1);
	}
	i = 0;
	while (i < philo->table->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
