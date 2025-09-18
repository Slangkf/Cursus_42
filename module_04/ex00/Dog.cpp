/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 11:41:06 by tclouet          ###   ########.fr       */
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
    return ;
}

Dog::~Dog(void){
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

void   Dog::makeSound(void) const{
    std::cout << "Waf Waf!" << std::endl;
    return ;
}
