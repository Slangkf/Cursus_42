/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:03:58 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/16 16:03:59 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	put_down_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

static void	enjoy_his_meal(t_philo *philo)
{
	ft_display_state_message(philo, "\033[33mis eating\033[0m");
	philo->last_meal = ft_get_current_time();
	pthread_mutex_lock(&philo->table->meal_lock);
	if (philo->table->meals_target != -1)
	{
		philo->nb_meals_eaten++;
		if (philo->nb_meals_eaten == philo->table->meals_target)
			philo->table->satiates++;
	}
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->time_toeat);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_display_state_message(philo, "\033[33mhas taken a fork\033[0m");
		pthread_mutex_lock(philo->r_fork);
		ft_display_state_message(philo, "\033[33mhas taken a fork\033[0m");
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_display_state_message(philo, "\033[33mhas taken a fork\033[0m");
		pthread_mutex_lock(philo->l_fork);
		ft_display_state_message(philo, "\033[33mhas taken a fork\033[0m");
	}
}

static void	one_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_display_state_message(philo, "\033[33mhas taken a fork\033[0m");
	while (ft_check_dead_flag(philo->table) == 0)
		ft_usleep(1);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_is_eating(t_philo *philo)
{
	if (philo->table->nb_philo == 1)
		one_philosopher(philo);
	else
	{
		take_forks(philo);
		enjoy_his_meal(philo);
		put_down_forks(philo);
	}
}
