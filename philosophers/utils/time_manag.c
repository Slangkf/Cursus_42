/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:54:10 by tclouet           #+#    #+#             */
/*   Updated: 2025/04/17 11:55:35 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	timestamp;
	size_t			seconds;
	size_t			microseconds;
	size_t			current_time;

	gettimeofday(&timestamp, NULL);
	seconds = timestamp.tv_sec;
	microseconds = timestamp.tv_usec;
	current_time = seconds * 1000 + microseconds / 1000;
	return (current_time);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < milliseconds)
		usleep(500);
}
