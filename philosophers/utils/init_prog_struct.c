/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:03:44 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/10 13:03:45 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_forks_array(t_program *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (write(2, "Forks array malloc error\n", 25));
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			pthread_mutex_destroy(&table->access_to_statemessage);
			free(table->forks);
			return (write(2, "Mutex init error\n", 17));
		}
		i++;
	}
	return (0);
}

static int	init_mutexes(t_program *table)
{
	if (pthread_mutex_init(&table->access_to_statemessage, NULL) != 0)
		return (write(2, "Mutex init error\n", 17));
	if (pthread_mutex_init(&table->access_to_mealstarget, NULL) != 0)
	{
		pthread_mutex_destroy(&table->access_to_statemessage);
		return (write(2, "Mutex init error\n", 17));
	}
	if (pthread_mutex_init(&table->access_to_deadflag, NULL) != 0)
	{
		pthread_mutex_destroy(&table->access_to_statemessage);
		pthread_mutex_destroy(&table->access_to_mealstarget);
		return (write(2, "Mutex init error\n", 17));
	}
	if (pthread_mutex_init(&table->access_to_starttime, NULL) != 0)
	{
		pthread_mutex_destroy(&table->access_to_statemessage);
		pthread_mutex_destroy(&table->access_to_mealstarget);
		pthread_mutex_destroy(&table->access_to_deadflag);
		return (write(2, "Mutex init error\n", 17));
	}
	return (0);
}

static int	fill_meals_target(int argc, char **argv)
{
	if (argc == 5)
		return (-1);
	else
		return (ft_atol(argv[5]));
}

int	ft_init_prog_structure(t_program *table, int argc, char **argv)
{
	table->nb_philo = ft_atol(argv[1]);
	if (init_mutexes(table) != 0)
		return (1);
	if (init_forks_array(table) != 0)
		return (1);
	table->meals_target = fill_meals_target(argc, argv);
	table->dead_flag = 0;
	table->time_todie = ft_atol(argv[2]);
	table->time_toeat = ft_atol(argv[3]);
	table->time_tosleep = ft_atol(argv[4]);
	table->start_time = ft_get_start_time();
	return (0);
}
