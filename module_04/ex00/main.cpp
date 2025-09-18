/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:26 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 12:21:42 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){

    const Animal*       a = new Animal();
    const Animal*       d = new Dog();
    const Animal*       c = new Cat();
    const WrongAnimal*  wa = new WrongAnimal();
    const WrongAnimal*  wc = new WrongCat();
    const WrongCat*     z = new WrongCat();

    std::cout << a->getType() << " " << std::endl;  //will output the animal type!
    std::cout << d->getType() << " " << std::endl;  //will output the dog type!
    std::cout << c->getType() << " " << std::endl;  //will output the cat type!
    std::cout << wa->getType() << " " << std::endl; //will output the WrongAnimal type!
    std::cout << wc->getType() << " " << std::endl; //will output the WrongCat type!
    std::cout << z->getType() << " " << std::endl;  //will output the WrongCat type!

    a->makeSound();  //will output the animal sound!
    d->makeSound();  //will output the dog sound!
    c->makeSound();  //will output the cat sound!
    wa->makeSound(); //will output the WrongAnimal sound!
    wc->makeSound(); //will output the WrongAnimal sound too because the makesound()
                     //function of WrongAnimal is not declared virtual!
    z->makeSound();  //will output the WrongCat sound!
    
    delete a;
    delete d;
    delete c;
    delete wa;
    delete wc;
    delete z;
    return 0;
}