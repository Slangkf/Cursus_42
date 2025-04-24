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
	if (philo->table->nb_philo % 2 == 1)
	{
		if (philo->id % 2 == 1)
			ft_usleep(philo->table->time_toeat / 2);
	}
}

static void	is_sleeping(t_philo *philo)
{
	ft_display_state_message(philo, "\033[34mis sleeping\033[0m");
	ft_usleep(philo->table->time_tosleep);
}

static void	synchro(t_philo	*philo)
{
	if (philo->id % 2 == 1)
	{
		is_thinking(philo);
		ft_usleep(philo->table->time_toeat / 2);
	}
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
	synchro(philo);
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
	int		i;

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
	ft_usleep(5);
	ft_init_start_time(philo, table);
	return (0);
}
