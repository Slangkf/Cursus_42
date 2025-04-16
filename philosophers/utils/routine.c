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
	ft_display_state_message(philo, "is thinking");
}

static void	is_sleeping(t_philo *philo)
{
	ft_display_state_message(philo, "is sleeping");
	usleep (philo->table->time_tosleep * 1000);
}

static int	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->access_to_deadflag);
	if (philo->table->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->table->access_to_deadflag);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->access_to_deadflag);
	return (0);
}

static void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id == 1)
		usleep(100);
	if (philo->id % 2 == 1 && philo->id != 1)
		usleep(150);
	while (check_dead_flag(philo) == 0)
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
		usleep(100);
		if (pthread_create(&philo[i].thread, NULL,
				&routine, &philo[i]) != 0)
		{
			ft_free_both_structures(philo, table);
			return (write(2, "Thread creating error\n", 22));
		}
		i++;
	}
	return (0);
}
