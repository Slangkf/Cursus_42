/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:13 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 13:31:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define  ANIMAL_HPP

#include <iostream>

class Animal{
    public:
        Animal(void);
        Animal(Animal const & src);
        virtual ~Animal(void);
        Animal & operator=(Animal const & rhs);
    
        std::string    getType(void) const;
        virtual void    makeSound(void) const;
    protected:
        std::string type;
};

#endif