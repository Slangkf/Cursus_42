/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/12 15:18:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0){

	return ;
}

Fixed::Fixed(int const i){
	
	this->_fixedPoint = i << _fractionalBits;
	return ;
}

Fixed::Fixed(float const f){

	this->_fixedPoint = roundf(f *(1 << _fractionalBits));
	return ;
}

Fixed::Fixed(Fixed const& src){

	*this = src;
	return ;
}

Fixed::~Fixed(void){

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

	return (float)this->_fixedPoint / (float)(1 << _fractionalBits);
}

int		Fixed::toInt(void) const{

	return this->_fixedPoint >> _fractionalBits;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b){

	if (a < b)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b){

	if (a > b)
		return a;
	else
		return b;
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b){

	if (a < b)
		return a;
	else
		return b;
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b){

	if (a > b)
		return a;
	else
		return b;
}

const int	Fixed::_fractionalBits = 8;
