/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:13 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 14:20:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define  AANIMAL_HPP

#include <iostream>

class AAnimal{
    public:
        AAnimal(void);
        AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);
        AAnimal & operator=(AAnimal const & rhs);
    
        std::string    getType(void) const;
        virtual void    makeSound(void) const = 0;
    protected:
        std::string type;
};

#endif