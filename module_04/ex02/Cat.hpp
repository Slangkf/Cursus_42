/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:25:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define  CAT_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"
#include <iostream>

class Cat: public AAnimal{
    public:
        Cat(void);
        Cat(Cat const & src);
        virtual ~Cat(void);
        Cat&    operator=(Cat const& rhs);

        void        makeSound(void) const;
        void        setCatIdea(int index, std::string idea);
        std::string getCatIdea(int index) const;
    private:
        Brain*  _attribute;
};

#endif