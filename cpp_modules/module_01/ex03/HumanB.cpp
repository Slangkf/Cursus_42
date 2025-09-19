/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:55:59 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/09 11:18:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL){
	std::cout << "HumanB Constructor is called" << std::endl;
	return ;
}

HumanB::~HumanB(void){
	std::cout << "HumanB Destructor is called" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& club){
	this->_weapon = &club;
	return ;
}

void	HumanB::attack(void){
	if (_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon !" << std::endl;
	return ;
}
