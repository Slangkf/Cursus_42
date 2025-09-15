/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:14:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:12:37 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){

    ScavTrap    a("Jim");
    ScavTrap    b("Bob");
    
    std::cout << std::endl;

    a.attack("DAVID");
    a.takeDamage(5);
    a.beRepaired(3);
    a.guardGate();

    std::cout << std::endl;

    b.attack("GOLIATH");
    b.takeDamage(200);
    b.beRepaired(3);
    b.guardGate();
    
    std::cout << std::endl;

    return 0;
}
