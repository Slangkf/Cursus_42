/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:07:37 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 12:18:38 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define  WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal(void);
        WrongAnimal & operator=(WrongAnimal const & rhs);
        std::string    getType(void) const;
        void    makeSound(void) const;
    protected:
        std::string type;
};

#endif