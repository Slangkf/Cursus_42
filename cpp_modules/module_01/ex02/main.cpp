/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:43:24 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/04 14:48:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int	main(void){
	
	std::string introduction = "HI THIS IS BRAIN";

	std::string	*stringPTR = &introduction;
	std::string	&stringREF = introduction;

	std::cout << "The memory adress of the variable is: " << &introduction << std::endl;
	std::cout << "The value of string variable is: " << introduction << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "The memory adress held by stringPTR is: " << stringPTR << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;

	std::cout << std::endl;
	
	std::cout << "The memory adress held by stringREF is: " << &stringREF << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;
	
	return (0);
}