/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:56:32 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/10 14:56:33 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	is_thinking(t_philo *philo)
{
	ft_display_state_message(philo, "\033[32mis thinking\033[0m");
}

static void	is_sleeping(t_philo *philo)
{
	ft_display_state_message(philo, "\033[34mis sleeping\033[0m");
	ft_usleep(philo->table->time_tosleep);
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

static void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->table->start_time_lock);
		if (philo->table->start_time != 0)
		{
			pthread_mutex_unlock(&philo->table->start_time_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->table->start_time_lock);
		ft_usleep(1);
	}
	philo->last_meal = philo->table->start_time;
	if (philo->id % 2 == 1)
		ft_usleep(1);
	while (ft_check_dead_flag(philo->table) == 0)
	{
		ft_is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

int	ft_start_routine(t_philo *philo, t_program *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL,
				&routine, &philo[i]) != 0)
		{
			free(philo);
			ft_free_table_struct(table);
			return (write(2, "Thread creating error\n", 22));
		}
		i++;
	}
	pthread_mutex_lock(&table->start_time_lock);
	table->start_time = ft_get_current_time();
	pthread_mutex_unlock(&table->start_time_lock);
	return (0);
}
