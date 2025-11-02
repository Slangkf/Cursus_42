/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/08 11:05:30 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void){
	std::cout << "We create a Data type object named test with three random values" << std::endl;
	Data	test(42, "PARIS", true);
	std::cout << "The adress of test is: " << &test << std::endl;
	std::cout << "The values stored in test are: ";
	std::cout << test.getInt()<< ", " << test.getString() << ", " << test.getBool() << std::endl;
	std::cout << std::endl;

	Data	*ptr = &test;
	std::cout << "We store the adress of test into a pointer named ptr: " << ptr << std::endl;
	uintptr_t reAdress = Serializer::serialize(ptr);
	std::cout << "Serialize() reinterpreted the hexa. adress into an integer value: " << reAdress << std::endl;
	std::cout << std::endl;

	std::cout << "Then, deserialize() does the opposite:" << std::endl;
	Data	*ptr2 = Serializer::deserialize(reAdress);
	std::cout << "The adress pointed to by ptr2 is: " << ptr2 << std::endl;
	std::cout << "The values pointed to by ptr2 are: ";
	std::cout << ptr2->getInt()<< ", " << ptr2->getString() << ", " << ptr2->getBool() << std::endl;
	return (0);
}
