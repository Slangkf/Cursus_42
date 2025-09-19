/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:20:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void){
    std::cout << "AAnimal default Constructor called" << std::endl;
    this->type = "AAnimal";
    return ;
}

AAnimal::AAnimal(AAnimal const& src){
    std::cout << "AAnimal copy Constructor called" << std::endl;
    *this = src;
    return ;
}

AAnimal::~AAnimal(void){
    std::cout << "AAnimal destructor called" << std::endl;
    return ;
}

AAnimal&   AAnimal::operator=(AAnimal const& rhs){
    std::cout << "AAnimal assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

std::string    AAnimal::getType(void) const{
    return this->type;
}
