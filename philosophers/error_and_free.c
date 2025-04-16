/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:26:10 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/11 13:32:25 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_table_structure(t_program *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->nb_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->access_to_statemessage);
	pthread_mutex_destroy(&table->access_to_mealstarget);
	pthread_mutex_destroy(&table->access_to_deadflag);
	pthread_mutex_destroy(&table->access_to_starttime);
}

void	ft_free_both_structures(t_philo *philo, t_program *table)
{
	free(philo);
	ft_free_table_structure(table);
}
