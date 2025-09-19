/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:23 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 11:40:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define  DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal{
    public:
        Dog(void);
        Dog(Dog const & src);
        ~Dog(void);
        void   makeSound(void) const;
};

#endif