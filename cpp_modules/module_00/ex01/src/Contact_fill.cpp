/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_fill.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:34:29 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 14:05:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void){

//	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void){

//	std::cout << "Contact destructor called" << std::endl;
	return ;
}

static int	checkNumEntry(const std::string &line){

	int	i;

	i = 0;
	while (line[i] && isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (0);
	i = 0;
	while (line[i])
	{
		if (!isdigit(line[i]) && line[i] != 32)
			return (std::cout << "Only numeric character authorized" << std::endl, 0);
		i++;
	}

	return (1);
}

static int	checkAlphaEntry(const std::string &line){

	int	i;

	i = 0;
	while (line[i] && isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (0);
	i = 0;
	while (line[i])
	{
		if (!isalpha(line[i]) && line[i] != 32)
			return (std::cout << "Only alphabetic character authorized" << std::endl, 0);
		i++;
	}
	return (1);
}

void Contact::fillContactFields(void){

	do {
		std::cout << "First Name: ";
		std::getline(std::cin, this->fName);
	} while (this->fName.empty() || !checkAlphaEntry(this->fName));
	do {
		std::cout << "Last Name: ";
		std::getline(std::cin, this->lName);
	} while (this->lName.empty() || !checkAlphaEntry(this->lName));
	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, this->nName);
	} while (this->nName.empty() || !checkAlphaEntry(this->nName));
	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, this->pNumber);
	} while (this->pNumber.empty() || !checkNumEntry(this->pNumber));
	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->dSecret);
	} while (this->dSecret.empty() || !checkAlphaEntry(this->dSecret));
	return ;
}
