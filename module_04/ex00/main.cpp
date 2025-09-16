/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:26 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 16:45:10 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){

    const Animal*       meta = new Animal();
    const Animal*       i = new Dog();
    const Animal*       j = new Cat();
    const WrongAnimal*  k = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;

    meta->makeSound();
    i->makeSound(); //will output the dog sound!
    j->makeSound(); //will output the cat sound!
    k->makeSound(); //will output the wrong cat sound!
    
    delete meta;
    delete i;
    delete j;
    delete k;
    return 0;
}