/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_display.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:51:49 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 12:48:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

static int	checkInput(const std::string &line, int n){
	
	int	i;

	i = 0;
	while (line[i])
	{
		if (!isdigit(line[i]))
			return (0);
		i++;
	}
	if (std::atoi(line.c_str()) < 0 || std::atoi(line.c_str()) > (n - 1))
		return (0);
	return (1);
}

static void	displayIndex(int i){
	
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << i;
	std::cout << "|";
	return ;
}

static void	displayHeader(void){
	
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "nickname";
	std::cout << "|" << std::endl;
	return ;
}

void PhoneBook::displayPhoneBook(void){
	
	int	i;
	std::string	input;

	if (!this->_nbContact)
	{
		std::cout << "There is no contact to display" << std::endl;
		return ;
	}
	displayHeader();
	i = 0;
	while (i < this->_nbContact)
	{
		displayIndex(i);
		this->contact[i].displayContacts();
		i++;
	}
	do {
		std::cout << "Please write the index of the contact to display: ";
		std::getline(std::cin, input);
	} while (input.empty() || !checkInput(input, this->_nbContact));
	this->contact[atoi(input.c_str())].displayChosenContact();
	return ;
}