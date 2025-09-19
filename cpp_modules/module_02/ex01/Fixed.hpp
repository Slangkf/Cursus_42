/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:28 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/11 13:35:17 by tclouet          ###   ########.fr       */
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
		Fixed&	operator=(Fixed const & rhs);
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream& os, Fixed const& x);

#endif