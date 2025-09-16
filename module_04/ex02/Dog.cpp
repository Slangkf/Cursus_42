/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:03:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
    std::cout << "Dog default Constructor called" << std::endl;
    this->type = "Dog";
    this->attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->attribute->setIdeas(i, "It is a Dog idea!");
    return ;
}

Dog::Dog(Dog const& src): Animal(src){
    std::cout << "Dog copy Constructor called" << std::endl;
    this->attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->attribute->setIdeas(i, src.attribute->getIdeas(i));
    return ;
}

Dog::~Dog(void){
    std::cout << "Dog destructor called" << std::endl;
    delete attribute;
    return ;
}

Dog&   Dog::operator=(Dog const& rhs){
    std::cout << "Dog assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
     for (int i = 0; i < 100; i++)
        this->attribute->setIdeas(i, rhs.attribute->getIdeas(i));
    }
    return *this;
}

void   Dog::makeSound(void) const{
    std::cout << "Waf Waf!" << std::endl;
    return ;
}

std::string Dog::getDogIdeas(int index) const{
    return this->attribute->getIdeas(index);
}
