/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 15:57:08 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
    std::cout << "Dog default Constructor called" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog(Dog const& src): Animal(src){
    std::cout << "Dog copy Constructor called" << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void){
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog&   Dog::operator=(Dog const& rhs){
    std::cout << "Dog assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

void   Dog::makeSound(void) const{
    std::cout << "Waf Waf!" << std::endl;
    return ;
}
