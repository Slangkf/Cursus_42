/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:28 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/12 10:46:35 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

	public:
		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const& src);
		~Fixed(void);
		
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
	
		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;
	
		Fixed&	operator=(Fixed const & rhs);
	
		Fixed&	operator++(void);	//pre-increment function.
		Fixed&	operator--(void);	//pre-decrement function.
		Fixed	operator++(int);	//'int' its only here to indicate that this is the post-increment
		Fixed	operator--(int);	//(or post-decrement) function but will never be used.
	
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
	
		float	toFloat(void) const;
		int		toInt(void) const;
	
		static	Fixed& min(Fixed& a, Fixed& b);
		static	Fixed& max(Fixed& a, Fixed& b);
		static	Fixed const& min(Fixed const& a, Fixed const& b);
		static	Fixed const& max(Fixed const& a, Fixed const& b);
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream& os, Fixed const& x);

#endif