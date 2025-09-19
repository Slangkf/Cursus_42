/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_fill.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:34:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 13:53:12 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void){

//	std::cout << "PhoneBook constructor called" << std::endl;
	this->_nbContact = 0;
	this->_olderContact = 0;
	this->_currentContact = 0;
	return ;
}

PhoneBook::~PhoneBook(void){

//	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void PhoneBook::addContact(void){

	if (this->_nbContact < 8)
	{
		this->contact[this->_currentContact].fillContactFields();
		this->_nbContact++;
		this->_currentContact++;	
	}
	else
	{
		this->contact[this->_olderContact].fillContactFields();
		if (this->_olderContact < 7)
			this->_olderContact++;
		else
			this->_olderContact = 0;
		this->_currentContact = this->_olderContact;
	}
	return ;
}
