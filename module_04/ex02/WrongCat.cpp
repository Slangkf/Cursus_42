/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:32 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 16:41:26 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
    std::cout << "WrongCat default Constructor called" << std::endl;
    this->type = "WrongCat";
    return ;
}

WrongCat::WrongCat(WrongCat const& src): WrongAnimal(src){
    std::cout << "WrongCat copy Constructor called" << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat&   WrongCat::operator=(WrongCat const& rhs){
    std::cout << "WrongCat assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

void   WrongCat::makeSound(void) const{
    std::cout << "MIAOU !" << std::endl;
    return ;
}