/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:20:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/29 14:19:21 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void){
	std::cout << "We create two valid instances of Bureaucrat"<< std::endl;
	Bureaucrat	Charles("Charles", 1);
	Bureaucrat	Oliver("Oliver", 150);
	std::cout << Charles << std::endl;
	std::cout << Oliver << std::endl;
	std::cout << std::endl;

	std::cout << "We are trying to increase Charles's grade"<< std::endl;
	try {
		Charles.incrementGrade();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << Charles << std::endl;
	std::cout << std::endl;

	std::cout << "We are trying to decrease Oliver's grade"<< std::endl;
	try {
		Oliver.decrementGrade();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << Oliver << std::endl;
	std::cout << std::endl;

	std::cout << "We try to create a new instance with a grade out of range"<< std::endl;
	try {
		Bureaucrat	Mabel("Mabel", 0);
		std::cout << Mabel << std::endl; //no output because the object has not been created.
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "We create a new instance and then assign it Charles's grade"<< std::endl;
	try {
		Bureaucrat	Mabel ("Mabel", 2);
		std::cout << Mabel << std::endl;
		Mabel = Charles;
		std::cout << Mabel << std::endl;
		Mabel.decrementGrade();
		std::cout << Mabel << std::endl;
		Mabel.incrementGrade();
		std::cout << Mabel << std::endl;
		Mabel.incrementGrade();
		std::cout << Mabel << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
