/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeManagement.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:41:34 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:33:36 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeManagement.hpp"

TimeManagement::TimeManagement(void){
	std::cout << "Default Constructor of TimeManagement called" << std::endl;
	return ;
}

TimeManagement::TimeManagement(TimeManagement const& src){
	std::cout << "Copy Constructor of TimeManagement called" << std::endl;
	(void)src;
	return;
}

TimeManagement::~TimeManagement(){
	std::cout << "Destructor of TimeManagement called" << std::endl;
	return ;
}

TimeManagement& TimeManagement::operator=(TimeManagement const& rhs){
	std::cout << "Assignment operator of TimeManagement called" << std::endl;
	(void)rhs;
	return *this;
}

struct timeval  TimeManagement::_start;
struct timeval  TimeManagement::_end;

void	TimeManagement::setStartTime(void){
	gettimeofday(&_start, NULL);
}

void	TimeManagement::setEndTime(void){
	gettimeofday(&_end, NULL);
}

double	TimeManagement::getDuration(void){
	double	seconds = _end.tv_sec - _start.tv_sec;
	double	useconds = _end.tv_usec - _start.tv_usec;
	double	duration = seconds * 1000000 + useconds;
	return duration;
}