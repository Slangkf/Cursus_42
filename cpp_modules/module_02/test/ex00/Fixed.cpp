/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/17 09:35:12 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0){

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src){

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void){
	
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

int 	Fixed::getRawBits(void) const{
	
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}
void 	Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
	return ;
}

const int	Fixed::_fractionalBits = 8;