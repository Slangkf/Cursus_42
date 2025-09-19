/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/17 10:10:08 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0){

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const i){
	
	std::cout << "Int constructor called" << std::endl;

	// Convert the integer into fixed-point format with 8 fractional bits.
	// The fractional part is forced to 0 since i has no decimal.
	// i << _fractionalBits = i * 2^8 = i * 256.
	this->_fixedPoint = i << _fractionalBits;
	return ;
}

Fixed::Fixed(float const f){

	std::cout << "Float constructor called" << std::endl;

	// Convert the float into fixed-point format with 8 fractional bits.
	// Multiply by 2^8 = 256 (1 << _fractionalBits) to shift the fractional 
	// part into integer space, then apply roundf() to avoid truncation errors.
	this->_fixedPoint = roundf(f *(1 << _fractionalBits));
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

int 	Fixed::getRawBits(void) const{
	
	return this->_fixedPoint;
}

void 	Fixed::setRawBits(int const raw){
	
	this->_fixedPoint = raw;
	return ;
}

float	Fixed::toFloat(void) const{
	
	// Convert back to float by dividing the fixed-point value by 2^8 = 256.
	// Cast to float for real, not integer, division !
	return (float)this->_fixedPoint / (float)(1 << _fractionalBits);
}

int		Fixed::toInt(void) const{
	
	// Convert to int by truncating the fractional bits.
	// Equivalent to dividing by 2^8 = 256.
	return this->_fixedPoint >> _fractionalBits;
}

Fixed&	Fixed::operator=(Fixed const& rhs){
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, Fixed const& rhs){
	
	os << rhs.toFloat();
	return os;
}

const int	Fixed::_fractionalBits = 8;
