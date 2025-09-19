/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:29 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:47:45 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
    std::cout << "WrongAnimal default Constructor called" << std::endl;
    this->type = "WrongAnimal";
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src){
    std::cout << "WrongAnimal copy Constructor called" << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

WrongAnimal&   WrongAnimal::operator=(WrongAnimal const& rhs){
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

void   WrongAnimal::makeSound(void) const{
    std::cout << "WrongAnimal sound!" << std::endl;
    return ;
}

std::string    WrongAnimal::getType(void) const{
    return this->type;
}