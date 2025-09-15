/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:02:53 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:25:25 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    std::cout << "ScavTrap default Constructor called" << std::endl;
    _hitPoints = 100; 
    _energyPoints = 50; 
    _attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const& src): ClapTrap(src){
    std::cout << "ScavTrap copy Constructor called" << std::endl;
    *this = src;
    return ;
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}

ScavTrap&   ScavTrap::operator=(ScavTrap const& rhs){
    std::cout << "ScavTrap assignement operator called" << std::endl;
    if (this != &rhs){
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void    ScavTrap::attack(const std::string& target){
    if (this->_hitPoints <= 0){
        std::cout << "ScavTrap " << this->_name << " cannot attack, he is K.O.!" << std::endl;
        return ;
    }
    else if (!this->_energyPoints){
        std::cout << "ScavTrap " << this->_name << " has no energy point to attack!" << std::endl;
        return ;
    }
    else {
        std::cout << "ScavTrap " << this->_name << " attacks ";
        std::cout << target << ", causing " << this->_attackDamage;
        std::cout << " point(s) of damage!";
        this->_energyPoints -= 1;
        std::cout << " ScavTrap " << this->_name << " has now " << this->_energyPoints << " energy point(s)!" << std::endl;
        return ;
    }
}

void    ScavTrap::guardGate(void){
    if (this->_hitPoints <= 0){
        std::cout << "ScavTrap " << this->_name << " cannot makes him in Gate keeper mode, he is K.O.!" << std::endl;
        return ;
    }
    else {
        std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
        return ;
    }
}
