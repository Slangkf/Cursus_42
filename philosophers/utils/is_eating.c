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
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

static void	enjoy_your_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->access_to_mealstarget);
	philo->last_meal = ft_get_step_time(philo);
	if (philo->table->meals_target != -1)
		philo->nb_meals_eaten++;
	pthread_mutex_unlock(&philo->table->access_to_mealstarget);
	usleep (philo->table->time_toeat * 1000);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_display_state_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		ft_display_state_message(philo, "has taken a fork");
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_display_state_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		ft_display_state_message(philo, "has taken a fork");
	}
}

void	ft_is_eating(t_philo *philo)
{
	take_forks(philo);
	ft_display_state_message(philo, "is eating");
	enjoy_your_meal(philo);
	put_down_forks(philo);
}
