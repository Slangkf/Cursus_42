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

static int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->access_to_deadflag);
	pthread_mutex_lock(&philo->table->access_to_mealstarget);
	if (ft_get_step_time(philo) - philo->last_meal >= philo->table->time_todie)
	{
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(&philo->table->access_to_deadflag);
		pthread_mutex_unlock(&philo->table->access_to_mealstarget);
		ft_display_state_message(philo, "is dead");
		return (1);
	}
	pthread_mutex_unlock(&philo->table->access_to_deadflag);
	pthread_mutex_unlock(&philo->table->access_to_mealstarget);
	return (0);
}

void	ft_start_monitoring(t_philo *philo)
{
	int	i;

	while (philo->table->dead_flag == 0)
	{
		i = 0;
		while (i < philo->table->nb_philo)
		{
			if (check_death(&philo[i]) == 1)
				break ;
			i++;
		}
	}
	if (philo->table->dead_flag == 1)
	{
		i = 0;
		while (i < philo->table->nb_philo)
		{
			pthread_join(philo[i].thread, NULL);
			i++;
		}
	}
}
