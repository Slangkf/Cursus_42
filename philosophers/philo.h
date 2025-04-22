/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/09 12:11:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

//structures
typedef struct s_program
{
	int				nb_philo;
	int				meals_target;
	int				satiates;
	int				dead_flag;
	size_t			time_todie;
	size_t			time_toeat;
	size_t			time_tosleep;
	size_t			start_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	deadflag_lock;
	pthread_mutex_t	start_time_lock;
	pthread_mutex_t	*forks;
}			t_program;

typedef struct s_philo
{
	int				id;
	int				nb_meals_eaten;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_program		*table;
}			t_philo;

//utils
t_philo	*ft_init_philo_array(t_program *table);

int		ft_init_prog_structure(t_program *table, int argc, char **argv);
int		ft_start_routine(t_philo *philo, t_program *table);
int		ft_check_input(int argc, char **argv);
int		ft_check_dead_flag(t_program *table);

void	ft_is_eating(t_philo *philo);
void	ft_start_monitoring(t_philo *philo);
void	ft_usleep(size_t milliseconds);
void	ft_display_state_message(t_philo *philo, char *message);
void	ft_free_table_struct(t_program *table);

size_t	ft_get_current_time(void);
size_t	ft_strlen(const char *s);

long	ft_atol(const char *argv);
#endif
