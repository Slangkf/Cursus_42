/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 12:45:00 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
	try {
		RPN::checkInput(argc, argv[1]);
		RPN::doOperation(argv[1]);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}
