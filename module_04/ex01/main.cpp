/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:26 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 19:23:41 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* array[100];

    //fills the array with 50 Dog classes and 50 Cat classes.
    for (int i = 0; i < 100; i++)
    {
        if (i < 50){
            array[i] = new Dog();
            array[i]->makeSound();
        }
        else{
            array[i] = new Cat();
            array[i]->makeSound();
        }
    }
    //deletes all the Animal classes and their associated Brain classes.
    for (int i = 0; i < 100; i++)
        delete array[i];
    delete j;
    delete i;
    return 0;
}