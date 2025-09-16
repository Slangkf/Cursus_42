/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:15:29 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define  CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>

class Cat: public Animal{
    public:
        Cat(void);
        Cat(Cat const & src);
        virtual ~Cat(void);
        Cat & operator=(Cat const & rhs);
        void        makeSound(void) const;
        std::string getCatIdeas(int index) const;
    private:
        Brain*  attribute;
};

#endif