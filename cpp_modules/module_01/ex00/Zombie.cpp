/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:15:35 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/18 12:14:14 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name){
	
	std::cout << this->_name << " is born" << std::endl;
	return ;
}

Zombie::~Zombie(void){

	std::cout << this->_name << " died" << std::endl;
	return ;
}

void Zombie::announce(void){
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}