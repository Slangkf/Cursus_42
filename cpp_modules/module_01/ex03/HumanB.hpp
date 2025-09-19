/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:02 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/05 11:25:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& club);
		void	attack(void);
	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
