/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:59:46 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/18 15:37:27 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOAR_BRAINZ_H
# define MOAR_BRAINZ_H

#include <iostream>

class Zombie{
	public:
		Zombie(void);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void);
	private:
		std::string	_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
