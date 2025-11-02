/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/17 11:31:37 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#define MAX_VALUE 20000

int main(void){
	std::srand(std::time(NULL));
	std::cout << "Test1: find the shortest and the longest span in our class" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "The shortest span is: " << sp.shortestSpan() << std::endl;
		std::cout << "The longest span is: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest2: add at least 10.000 numbers to our class"<< std::endl;
	try {
		Span sp = Span(MAX_VALUE);
		for (int i = 0; i < MAX_VALUE; i++)
			sp.addNumber(std::rand());
		std::cout << "Number of elements stored into sp: " << sp.getNumberOfElements() << std::endl;
		std::cout << "Min value: " << sp.getMinValue() << std::endl;
		std::cout << "Max value: " << sp.getMaxValue() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "\nTest3: we try to add a number in our full class"<< std::endl;
		sp.addNumber(-42);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest4: add many numbers without multiple calls to addNumber()"<< std::endl;
	try {
		std::vector<int> v1;
		v1.push_back(2);
		v1.push_back(9);
		v1.push_back(-5);
		v1.push_back(19);
		Span	sp(v1.size());
		sp.addMultipleNumbers(v1.begin(), v1.end());
		std::cout << "Number of elements stored into sp: " << sp.getNumberOfElements() << std::endl;
		std::cout << "The content of sp is: " << std::endl;
		sp.displayElements();
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}