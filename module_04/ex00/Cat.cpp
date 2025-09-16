/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 15:57:01 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
    std::cout << "Cat default Constructor called" << std::endl;
    this->type = "Cat";
    return ;
}

Cat::Cat(Cat const& src): Animal(src){
    std::cout << "Cat copy Constructor called" << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat&   Cat::operator=(Cat const& rhs){
    std::cout << "Cat assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

void   Cat::makeSound(void) const{
    std::cout << "MEOOOOOWWW" << std::endl;
    return ;
}
