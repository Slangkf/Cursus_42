/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:14:11 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:15:21 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const& src){
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap::~ClapTrap(void){
    std::cout << "Destructor called" << std::endl;
    return ;
}

ClapTrap&   ClapTrap::operator=(ClapTrap const& rhs){
    std::cout << "Assignement operator called" << std::endl;
    if (this != &rhs){
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void    ClapTrap::attack(const std::string& target){
    if (this->_hitPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " cannot attack, he is K.O.!" << std::endl;
        return ;
    }
    else if (!this->_energyPoints){
        std::cout << "ClapTrap " << this->_name << " has no energy point to attack!" << std::endl;
        return ;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " attacks ";
        std::cout << target << ", causing " << this->_attackDamage;
        std::cout << " point(s) of damage!";
        this->_energyPoints -= 1;
        std::cout << " ClapTrap " << this->_name << " has now " << this->_energyPoints << " energy point(s)!" << std::endl;
        return ;
    }
}

void    ClapTrap::takeDamage(unsigned int amount){
    if (this->_hitPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " cannot take anymore damages, is already K.O.!" << std::endl;
        return ;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " point(s) of damage!";
        this->_hitPoints -= amount;
        if (this->_hitPoints > 0)
            std::cout << " ClapTrap " << this->_name << " has now " << this->_hitPoints << " hit point(s)!" << std::endl;
        else
            std::cout << " ClapTrap " << this->_name << " has no more hit point, he is K.O.!!" << std::endl;
        return ;
    }
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->_hitPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " cannot heal himself, he is K.O.!" << std::endl;
        return ;
    }
    else if (!this->_energyPoints){
        std::cout << "ClapTrap " << this->_name << " has no energy point to heals himself!" << std::endl;
        return ;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " heals " << amount << " hit point(s)!";
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << " ClapTrap " << this->_name << " has now " << this->_hitPoints << " hit point(s)";
        std::cout << " and " << this->_energyPoints << " energy point(s)!" << std::endl;
        return ;
    }
}