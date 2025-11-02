/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/17 11:26:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void){

	std::list<int>	lst;
	lst.push_back(1);
	lst.push_back(23);
	lst.push_back(3);

	try {
		std::list<int>::const_iterator	it;
		it = easyFind(lst, 3);
		std::cout << "Occurrence of " << *it << " found" << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	v;
	v.push_back(1);
	v.push_back(23);
	v.push_back(3);
	try {
		std::vector<int>::const_iterator	it;
		it = easyFind(v, 42);
		std::cout << "Occurrence of " << *it << " found" << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
    return 0;
}
