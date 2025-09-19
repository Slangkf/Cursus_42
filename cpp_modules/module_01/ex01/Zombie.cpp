/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:59:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/18 15:39:44 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	std::cout << "A new Zombie is born" << std::endl;
	return ;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
	return ;	
}

void	Zombie::setName(std::string name){
	this->_name = name;
	return ;
}

void	Zombie::announce(void){
	std::cout << "Zombie " << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}