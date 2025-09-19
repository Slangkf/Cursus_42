/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:11 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/05 10:05:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	
	public:
		Weapon(std::string value);
		~Weapon(void);
		void	setType(std::string type);
		std::string const& getType(void);
	private:
		std::string	_type;
};

#endif