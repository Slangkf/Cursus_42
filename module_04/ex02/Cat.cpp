/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:31:58 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
    std::cout << "Cat default Constructor called" << std::endl;
    this->type = "Cat";
    this->attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->attribute->setIdeas(i, "It is a Cat idea!");
    return ;
}

Cat::Cat(Cat const& src): AAnimal(src){
    std::cout << "Cat copy Constructor called" << std::endl;
    this->attribute = new Brain();
    for (int i = 0; i < 100; i++)
        this->attribute->setIdeas(i, src.attribute->getIdeas(i));
    return ;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    delete attribute;
    return ;
}

Cat&   Cat::operator=(Cat const& rhs){
    std::cout << "Cat assignement operator called" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
        for (int i = 0; i < 100; i++)
            this->attribute->setIdeas(i, rhs.attribute->getIdeas(i));
    }
    return *this;
}

void   Cat::makeSound(void) const{
    std::cout << "MEOOOOOWWW" << std::endl;
    return ;
}

std::string Cat::getCatIdeas(int index) const{
    return this->attribute->getIdeas(index);
}