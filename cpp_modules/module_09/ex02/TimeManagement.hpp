/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeManagement.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:41:32 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:28:06 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_MANAGEMENT_CPP
# define TIME_MANAGEMENT_CPP

#include <iostream>
#include <sys/time.h>

class	TimeManagement{
	public:
		static void		setStartTime(void);
		static void		setEndTime(void);
		static double	getDuration(void);
	private:
		TimeManagement(void);
		TimeManagement(TimeManagement const& src);
		~TimeManagement();
		TimeManagement& operator=(TimeManagement const& rhs);
		static struct timeval _start;
		static struct timeval _end;
};

#endif