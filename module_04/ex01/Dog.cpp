/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 13:43:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
    std::cout << "Dog default Constructor called" << std::endl;
    this->type = "Dog";
    this->_attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->_attribute->setIdea(i, "It is a Dog idea!");
    return ;
}

Dog::Dog(Dog const& src): Animal(src){
    std::cout << "Dog copy Constructor called" << std::endl;
    this->_attribute = new Brain(*src._attribute);
    return ;
}

Dog::~Dog(void){
    delete _attribute;
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog&   Dog::operator=(Dog const& rhs){
    std::cout << "Dog assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
     for (int i = 0; i < 100; i++)
        this->_attribute->setIdea(i, rhs._attribute->getIdea(i));
    }
    return *this;
}

void   Dog::makeSound(void) const{
    std::cout << "Waf Waf!" << std::endl;
    return ;
}

void    Dog::setDogIdea(int index, std::string idea){
    if (index >= 0 && index < 100)
        this->_attribute->setIdea(index, idea);
    else
        std::cerr << "Bad index!" << std::endl;
    return ;
}

std::string Dog::getDogIdea(int index) const{
    if (index >= 0 && index < 100)
        return this->_attribute->getIdea(index);
    else{
        std::cerr << "Bad index!" << std::endl;
        return "Bad index!";
    }
}
