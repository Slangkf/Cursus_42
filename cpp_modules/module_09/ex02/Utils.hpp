/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:37:57 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:36:01 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <exception>
#include <climits>
#include <cstdlib>

void	checkInput(int argc, char **argv);
bool	new_isdigit(char **argv);
bool	isGoodInteger(char **argv);
void	displayUnsortedSequence(char **argv);

class	TooFewArgumentsException: public std::exception{
	public:
		const char * what() const throw();
};

class	InvalidArgumentException: public std::exception{
	public:
		const char * what() const throw();
};

template <typename T>
void	displaySortedSequence(T const& container){
	typename	T::const_iterator	it = container.begin();
	typename	T::const_iterator	ite = container.end();
	bool							first = true;
	std::cout << "After:  ";
	for (; it != ite; ++it){
		if (!first)
			std::cout << " ";	
		std::cout << *it;
		first = false;
	}
	std::cout << std::endl;
}

template <typename T>
void	displayResult(double duration, T const& container, const char* type){
	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with " << type << " : ";
	std::cout << duration << " us" << std::endl;
}

template <typename T>
void	fillContainer(char **argv, T& container){
	for (int i = 1; argv[i]; i++)
		container.push_back(atoi(argv[i]));
}

#endif