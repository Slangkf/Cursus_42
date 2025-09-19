/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:03 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/17 13:50:38 by tclouet          ###   ########.fr       */
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
    return ;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
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
