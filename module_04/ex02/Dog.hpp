/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:23 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:09:28 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define  DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal{
    public:
        Dog(void);
        Dog(Dog const & src);
        virtual ~Dog(void);
        Dog & operator=(Dog const & rhs);
        void        makeSound(void) const;
        std::string getDogIdeas(int index) const;
    private:
        Brain*  attribute;
};

#endif