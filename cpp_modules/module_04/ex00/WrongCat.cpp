/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:32 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 11:52:42 by tclouet          ###   ########.fr       */
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
    return ;
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

void   WrongCat::makeSound(void) const{
    std::cout << "WrongCat sound!" << std::endl;
    return ;
}