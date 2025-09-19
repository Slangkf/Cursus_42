/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:12:35 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/09 10:22:40 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Constructor is called" << std::endl;
	return ;
}

Harl::~Harl(void){
	std::cout << "Destructor is called" << std::endl;
	return ;
}

void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complaint[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	int	i = 0;
	while (i < 4){
		if (levels[i] == level)
		{
			std::cout << "[" << levels[i] << "]" << std::endl;
			(this->*complaint[i])();
			return ;
		}
		i++;
	}
	std::cout << "[INAUDIBLE]" << std::endl;
	std::cout << "Probably complaining about insignificant problem" << std::endl;
	return ;
}

void Harl::debug(void){
	std::cout << "I love having..." << std::endl;
	return ;
}

void Harl::info(void){
	std::cout << "I cannot believe..." << std::endl;
	return ;
}

void Harl::warning(void){
	std::cout << "I think I deserve..." << std::endl;
	return ;
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}
