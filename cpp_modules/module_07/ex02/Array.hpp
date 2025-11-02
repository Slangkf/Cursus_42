/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:53:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/10 11:31:04 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array{
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const& src);
		~Array<T>(void);
		Array<T>&	operator=(Array<T> const& rhs);
		T const&	operator[](unsigned int index) const;
		T&			operator[](unsigned int index);

		unsigned int	size(void) const;

		class	OutOfBoundsIndexException: public std::exception{
			public:
				const char * what() const throw();
		};
	private:
		T*				_array;
		unsigned int	_size;
		
};

#include "Array.tpp"

#endif