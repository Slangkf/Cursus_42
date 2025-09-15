/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:03 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:43:09 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
    std::cout << "FragTrap default Constructor called" << std::endl;
    _hitPoints = 100; 
    _energyPoints = 100; 
    _attackDamage = 30;
    return ;
}

FragTrap::FragTrap(FragTrap const& src): ClapTrap(src){
    std::cout << "FragTrap copy Constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

FragTrap&   FragTrap::operator=(FragTrap const& rhs){
    std::cout << "FragTrap assignement operator called" << std::endl;
    if (this != &rhs){
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void    FragTrap::highFivesGuys(){
    if (this->_hitPoints <= 0){
        std::cout << "FragTrap " << this->_name << " cannot ask for a high five, he is K.O.!" << std::endl;
        return ;
    }
    else {
        std::cout << "FragTrap " << this->_name << " asks for a high five!" << std::endl;
        return ;
    }
}
