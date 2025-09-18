/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:48:09 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
    std::cout << "Animal default Constructor called" << std::endl;
    this->type = "Animal";
    return ;
}

Animal::Animal(Animal const& src){
    std::cout << "Animal copy Constructor called" << std::endl;
    *this = src;
    return ;
}

Animal::~Animal(void){
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

Animal&   Animal::operator=(Animal const& rhs){
    std::cout << "Animal assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

void   Animal::makeSound(void) const{
    std::cout << "Animal sound!" << std::endl;
    return ;
}

std::string    Animal::getType(void) const{
    return this->type;
}
