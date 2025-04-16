/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:26:49 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/16 16:16:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	set_new_philosopher(t_philo *philo, t_program *table, int i)
{
	philo->id = i + 1;
	philo->nb_meals_eaten = 0;
	philo->last_meal = 0;
	philo->l_fork = &table->forks[i];
	philo->r_fork = &table->forks[(i + 1) % table->nb_philo];
	philo->table = table;
}

t_philo	*ft_init_philo_array(t_program *table)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
	{
		ft_free_table_structure(table);
		write(2, "Array malloc error\n", 19);
		return (NULL);
	}
	i = 0;
	while (i < table->nb_philo)
	{
		set_new_philosopher(&philo[i], table, i);
		i++;
	}
	return (philo);
}
