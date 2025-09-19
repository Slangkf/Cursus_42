/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 12:03:16 by tclouet          ###   ########.fr       */
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
    return ;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

void   Cat::makeSound(void) const{
    std::cout << "Miaou !" << std::endl;
    return ;
}
