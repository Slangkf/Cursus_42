/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:14:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 12:04:07 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){

    ClapTrap    a("Jim");
    ClapTrap    b("Bob");

    a.attack("DAVID");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << std::endl;

    b.attack("GOLIATH");
    b.takeDamage(11);
    b.beRepaired(3);

    std::cout << std::endl;

    b = a;
    b.attack("GOLIATH");
    b.takeDamage(7);
    b.beRepaired(3);

    return 0;
}