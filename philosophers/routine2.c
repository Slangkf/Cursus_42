/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:10:30 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/15 17:10:32 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_dead_flag(t_philo *philo)
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
