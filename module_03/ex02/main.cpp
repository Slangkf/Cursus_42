/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:14:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/15 15:38:21 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void){

    FragTrap    a("Jim");
    FragTrap    b("Bob");
    
    std::cout << std::endl;

    a.attack("DAVID");
    a.takeDamage(5);
    a.beRepaired(3);
    a.highFivesGuys();

    std::cout << std::endl;

    b.attack("GOLIATH");
    b.takeDamage(200);
    b.beRepaired(3);
    b.highFivesGuys();
    
    std::cout << std::endl;

    return 0;
}
