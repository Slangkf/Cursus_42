/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:47:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
    std::cout << "Cat default Constructor called" << std::endl;
    this->type = "Cat";
    this->_attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->_attribute->setIdea(i, "It is a Cat idea!");
    return ;
}

Cat::Cat(Cat const& src): Animal(src){
    std::cout << "Cat copy Constructor called" << std::endl;
    this->_attribute = new Brain(*src._attribute);
    return ;
}

Cat::~Cat(void){
    delete _attribute;
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat&   Cat::operator=(Cat const& rhs){
    std::cout << "Cat assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
        for (int i = 0; i < 100; i++)
            this->_attribute->setIdea(i, rhs._attribute->getIdea(i));
    }
    return *this;
}

void   Cat::makeSound(void) const{
    std::cout << "Miaou!" << std::endl;
    return ;
}

void    Cat::setCatIdea(int index, std::string idea){
    if (index >= 0 && index < 100)
        this->_attribute->setIdea(index, idea);
    else
        std::cerr << "Bad index!" << std::endl;
    return ;
}

std::string Cat::getCatIdea(int index) const{
    if (index >= 0 && index < 100)
        return this->_attribute->getIdea(index);
    else{
        std::cerr << "Bad index!" << std::endl;
        return "Bad index!";
    }
}
