/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:55:54 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/05 10:12:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club): _name(name), _weapon(club){
	std::cout << "HumanA Constructor is called" << std::endl;
	return ;
}

HumanA::~HumanA(void){
	std::cout << "HumanA Destructor is called" << std::endl;
	return ;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}
