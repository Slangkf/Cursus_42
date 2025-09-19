/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_display.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:55:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 14:09:04 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"


void Contact::displayChosenContact(void) const{

	std::cout << "First name: " << this->fName << std::endl;
	std::cout << "Last name: " << this->lName << std::endl;
	std::cout << "Nickname: " << this->nName << std::endl;
	std::cout << "Phone number: " << this->pNumber << std::endl;
	std::cout << "Darkest secret: " << this->dSecret << std::endl;
	return ;
}

static void	displayTruncateLine(const std::string &line){

	std::string	output;

	output = line.substr(0, 9);
	output += ".";
	std::cout << std::setw(10) << std::right;
	std::cout << output;
}

void Contact::displayContacts(void) const{
	
	if (this->fName.length() > 10)
		displayTruncateLine(this->fName);
	else
	{
		std::cout << std::setw(10) << std::right;
		std::cout << this->fName;
	}
	std::cout << "|";
	if (this->lName.length() > 10)
		displayTruncateLine(this->lName);
	else
	{
		std::cout << std::setw(10) << std::right;
		std::cout << this->lName;
	}
	std::cout << "|";
	if (this->nName.length() > 10)
		displayTruncateLine(this->nName);
	else
	{
		std::cout << std::setw(10) << std::right;
		std::cout << this->nName;
	}
	std::cout << "|" << std::endl;
	return ;
}
