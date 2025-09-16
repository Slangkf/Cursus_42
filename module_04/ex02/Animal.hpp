/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:13 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:28:23 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define  ANIMAL_HPP

#include <iostream>

class AAnimal{
    public:
        AAnimal(void);
        AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);
        AAnimal & operator=(AAnimal const & rhs);
        virtual std::string    getType(void) const = 0;
        virtual void    makeSound(void) const = 0;
    protected:
        std::string type;
};

#endif