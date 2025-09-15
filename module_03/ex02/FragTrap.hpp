/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:37:23 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const& src);
        ~FragTrap(void);
        FragTrap& operator=(FragTrap const& rhs);
        void    highFivesGuys(void);
};

#endif