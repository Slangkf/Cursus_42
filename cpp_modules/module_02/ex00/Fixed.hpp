/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:28 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/10 14:50:49 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

	public:
		Fixed(void);
		Fixed(Fixed const& src);
		~Fixed(void);
		Fixed& operator=(Fixed const & rhs);
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};

#endif