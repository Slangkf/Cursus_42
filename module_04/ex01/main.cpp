/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:45:26 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 13:54:05 by tclouet          ###   ########.fr       */
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
    /*We create two Animal pointers, one to a Dog class and the other to a Cat class
    and delete them at the end of the main function to check for leaks.*/
    const Animal* ad = new Dog();
    const Animal* ac = new Cat();
    std::cout << std::endl;

    /*We create a Dog pointer, replace an old idea with the sentence of our choice,
    then check if it is a deep copy or not.*/
    Dog*  d = new Dog();
    d->setDogIdea(8, "it is a deep copy");
    {
        Dog b(*d);
        std::cout << b.getDogIdea(8) << std::endl;
    }
    std::cout << d->getDogIdea(8) << std::endl;
    std::cout << std::endl;

    /*We fill an array with half Dog and half Cat, then we call the makesound() function to check 
    the creation and finaly deletes all the Animal classes and their associated Brain classes to check for leaks.*/
    const Animal* array[4];
    for (int i = 0; i < 4; i++)
    {
        if (i < 2){
            array[i] = new Dog();
            array[i]->makeSound();
        }
        else{
            array[i] = new Cat();
            array[i]->makeSound();
        }
    }
    for (size_t i = 0; i < 4; i++)
        delete array[i];
    std::cout << std::endl;

    delete ad;
    delete ac;
    delete d;
    return 0;
}
