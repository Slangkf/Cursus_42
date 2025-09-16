/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 15:48:18 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define  CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat: public Animal{
    public:
        Cat(void);
        Cat(Cat const & src);
        ~Cat(void);
        Cat & operator=(Cat const & rhs);
        void    makeSound(void) const;
};

#endif