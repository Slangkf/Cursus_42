/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:12 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/09 15:07:13 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	table;
	t_philo		*philo;

	if (ft_check_input(argc, argv) != 0)
		return (write(2, "Wrong argument(s)\n", 18));
	if (ft_init_prog_structure(&table, argc, argv) != 0)
		return (write(2, "Prog_structure init error\n", 26));
	philo = ft_init_philo_array(&table);
	if (!philo)
		return (write(2, "Philo_array init error\n", 27));
	if (ft_start_routine(philo, &table) != 0)
		return (write(2, "Thread creation error\n", 27));
	ft_start_monitoring(philo);
	ft_free_table_struct(&table);
	free(philo);
	return (0);
}
