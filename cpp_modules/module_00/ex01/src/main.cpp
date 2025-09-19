/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:34:24 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 13:53:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void){

	PhoneBook	myPhoneBook;
	std::string	input;

	while (1)
	{
		std::cout << "Choose your command between ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			myPhoneBook.addContact();
		else if (input == "SEARCH")
			myPhoneBook.displayPhoneBook();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}