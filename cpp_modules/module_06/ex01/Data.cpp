/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:44:56 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 14:52:01 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int x, std::string y, bool z): _x(x), _y(y), _z(z){
	//std::cout << "Default constructor of Data called" << std::endl;
	return ;
}

Data::Data(Data const& src){
	//std::cout << "Copy constructor of Data called" << std::endl;
	*this = src;
	return ;
}

Data::~Data(void){
	//std::cout << "Destructor of Data called" << std::endl;
	return ;
}

Data& Data::operator=(Data const& rhs){
	//std::cout << "Copy assignment operator of Data called" << std::endl;
	(void)rhs;
	return *this;
}

int	Data::getInt(void){
	return this->_x;
}

std::string	Data::getString(void){
	return this->_y;
}

std::string	Data::getBool(void){
	if (_z)
		return "OK";
	else
		return "NOK"; 
}