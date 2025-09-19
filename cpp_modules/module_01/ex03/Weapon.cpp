/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/05 10:12:34 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string value){
	std::cout << "Weapon Constructor is called" << std::endl;
	setType(value);
	return ;
}

Weapon::~Weapon(void){
	std::cout << "Weapon Destructor is called" << std::endl;
	return ;
}

void	Weapon::setType(std::string type){
	this->_type = type;
	return ;
}

std::string const& Weapon::getType(void){
	return (_type);
}