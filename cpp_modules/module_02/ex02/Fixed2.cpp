/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:05:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/17 10:23:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator>(Fixed const& rhs) const{
	
	return this->_fixedPoint > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const& rhs) const{
	
	return this->_fixedPoint < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const& rhs) const{
	
	return this->_fixedPoint >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const& rhs) const{
	
	return this->_fixedPoint <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const& rhs) const{
	
	return this->_fixedPoint == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const& rhs) const{
	
	return this->_fixedPoint != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const& rhs) const{
	
	Fixed	temp;
	temp.setRawBits(this->_fixedPoint + rhs.getRawBits());
	return 	temp;
}

Fixed	Fixed::operator-(Fixed const& rhs) const{
	
	Fixed	temp;
	temp.setRawBits(this->_fixedPoint - rhs.getRawBits());
	return temp;
}

Fixed	Fixed::operator*(Fixed const& rhs) const{
	
	Fixed	temp;
	// The product must be divided by 256 (>> _fractionalBits in binary)
	// to correct the scale, since both operands are already in fixed-point format.
	temp.setRawBits((this->_fixedPoint * rhs.getRawBits()) >> _fractionalBits);
	return temp;
}

Fixed	Fixed::operator/(Fixed const& rhs) const{
	
	Fixed	temp;
	if (rhs.getRawBits() == 0){
		std::cerr << "Warning: the divisor value is 0, I return Fixed(0) by default." << std::endl;
		return temp;
	}
	// The fixed-point of the current instance must be multiplied by 256 (<< _fractionalBits)
	// a second time (double scale) before being divided by the fixed-point of rhs.
	temp.setRawBits((this->_fixedPoint << _fractionalBits) / rhs.getRawBits());
	return temp;
}

Fixed&	Fixed::operator=(Fixed const& rhs){
	
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

Fixed&	Fixed::operator++(void){
	
	// 1 unite of _fixedPoint corresponds to epsilon (1 / 2^_fractionalBits 
	// or 1/256 in real value) so we simply increase its value by 1.
	this->_fixedPoint += 1;
	return *this;
}

Fixed&	Fixed::operator--(void){
	
	this->_fixedPoint -= 1;
	return *this;
}

Fixed	Fixed::operator++(int){
	
	Fixed	copy = *this;	//We save a copy of our current instance *this.
	this->_fixedPoint += 1;	//We increment the fixed-point number of our current instance.
	return copy;			//We return the copy of our current instance (without the incremented value).
}

Fixed	Fixed::operator--(int){
	
	Fixed	copy = *this;
	this->_fixedPoint -= 1;
	return copy;
}

std::ostream&	operator<<(std::ostream& os, Fixed const& rhs){
	
	os << rhs.toFloat();
	return os;
}