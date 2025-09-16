/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:53:12 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 18:58:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default Constructor called" << std::endl;
    return ;
}

Brain::Brain(Brain const& src){
    std::cout << "Brain copy Constructor called" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain(void){
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain&   Brain::operator=(Brain const& rhs){
    std::cout << "Brain assignement operator called" << std::endl;
    if (this != &rhs){
        for (int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
    return *this;
}

void    Brain::setIdeas(int index, const std::string& idea){
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
    else
        std::cerr << "Bad index !" << std::endl;
    return ;
}

std::string Brain::getIdeas(int index) const{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    else
    {
        std::cerr << "Bad index !" << std::endl;
        return NULL;
    }
}