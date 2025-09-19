/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:55:57 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/05 09:56:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon& club);
		~HumanA(void);
		void	attack(void);
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif
