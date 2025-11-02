/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/17 11:08:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main(void){
	std::cout << "TEST1: we create a MutantStack object and add some numbers" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << "\nThe element at the top of the stack is: " << mstack.top() << std::endl;
	std::cout << "If we remove the first element, the stack contains: ";
	mstack.pop();
	ite = mstack.end();
	for (it = mstack.begin(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << "\nAnd it size is: "<< mstack.size() << std::endl;

	std::cout << "\nTEST2: we add four more numbers to our stack" << std::endl;
	mstack.push(3);
	mstack.push(9);
	mstack.push(737);
	mstack.push(0);
	it = mstack.begin();
	++it;
	ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << "\nSo the stack contains now: " << std::endl;
	ite = mstack.end();
	for (it = mstack.begin(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "\nTEST3: we check the copy from mstack to std::stack" << std::endl;
	{
		std::stack<int> s(mstack);
		std::cout << "We check if the copy is successful: ";
		it = mstack.begin();
		ite = mstack.end();
		--ite;
		size_t	j = s.size();
		bool	check = true;
		for (size_t i = 0; i < j; i++){
			if (s.top() != *ite){
				std::cout << "No...";
				check = false;
			}
			s.pop();
			if (ite != it)
				--ite;
		}
		if (check == true)
			std::cout << "Yes!" << std::endl;
	}
	std::cout << "We check if the content of mstack still exists: ";
	ite = mstack.end();
	for (it = mstack.begin(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nTEST4: we must have the same results with a list instead of mstack" << std::endl;
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	std::list<int>::iterator	it2 = lst.begin();
	std::list<int>::iterator	ite2 = lst.end();
	for (; it2 != ite2; ++it2)
		std::cout << *it2 << " ";
	std::cout << "\nThe element at the top of lst is: " << lst.back() << std::endl;
	std::cout << "If we remove the first element, lst contains: ";
	lst.pop_back();
	ite2 = lst.end();
	for (it2 = lst.begin(); it2 != ite2; ++it2)
		std::cout << *it2 << " ";
	std::cout << "\nAnd it size is: "<< lst.size() << std::endl;
	std::cout << "We add four more numbers to lst" << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	it2 = lst.begin();
	++it2;
	ite2 = lst.end();
	for (; it2 != ite2; ++it2)
		std::cout << *it2 << " ";
	std::cout << "\nSo lst contains now: " << std::endl;
	ite2 = lst.end();
	for (it2 = lst.begin(); it2 != ite2; ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;	
	return 0;
}
