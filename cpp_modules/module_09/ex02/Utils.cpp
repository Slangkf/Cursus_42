/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:37:59 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:36:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void	checkInput(int argc, char **argv){
	if (argc == 1)
		throw TooFewArgumentsException();
	else if (!new_isdigit(argv))
		throw InvalidArgumentException();
	else if (!isGoodInteger(argv))
		throw InvalidArgumentException();
}

bool	new_isdigit(char **argv){
	for (int i = 1; argv[i]; i++){
		for (int j = 0; argv[i][j]; j++){
			if (!isdigit(argv[i][j]))
				return false;
		}
	}
	return true;
}

bool	isGoodInteger(char **argv){
	long	input;

	for (int i = 1; argv[i]; i++){
		input = atol(argv[i]);
		if (input < 0 || input > INT_MAX)
			return false;	
	}
	return true;
}

void	displayUnsortedSequence(char **argv){
	bool	first = true;

	std::cout << "Before: ";
	for (int i = 1; argv[i]; i++){
		if (!first)
			std::cout << " ";
		std::cout << argv[i];
		first = false;
	}
	std::cout << std::endl;
}

const char * TooFewArgumentsException::what() const throw(){
	return "Error: at least 1 positive integer required";
}

const char * InvalidArgumentException::what() const throw(){
	return "Error: invalid argument found";
}
