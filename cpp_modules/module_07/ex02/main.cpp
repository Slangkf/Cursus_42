/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/10 13:28:58 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_VAL 750

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));

	std::cout << "We set the elements of our arrays to random values" << std::endl;
	for (int i = 0; i < MAX_VAL; i++){
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << "Next we check if the values are correctly stored in numbers: ";
	for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "a different value was saved..." << std::endl;
            return 1;
        }
    }
	std::cout << "the same values have been saved!" << std::endl;
	std::cout << std::endl;

	std::cout << "We check the assignment operator and the copy constructor" << std::endl;
	{
        Array<int> tmp;
		tmp = numbers;
		std::cout << "Value stored in tmp[42]: " << tmp[42] << std::endl;
        Array<int> const test(tmp);
		std::cout << "Value stored in test[42]: " << test[42] << std::endl;
    }
	std::cout << std::endl;

	std::cout << "Next we try to access to invalid indexes of our arrays: " << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;

	std::cout << "Then we try to change the values stored in our array" << std::endl;
	std::cout << "The initial value stored in numbers[42] was: " << numbers[42] << std::endl;
    for (int i = 0; i < MAX_VAL; i++){
	    numbers[i] = std::rand();	
	}
	std::cout << "The new value is: " << numbers[42] << std::endl;
    delete [] mirror;
    return 0;
}