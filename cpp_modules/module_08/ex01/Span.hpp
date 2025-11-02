/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:18:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/16 10:25:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
	public:
		Span(unsigned int limit);
		Span(Span const& src);
		~Span();
		Span& operator=(Span const& rhs);

		void	addNumber(int value);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addMultipleNumbers(std::vector<int>::const_iterator it,
				std::vector<int>::const_iterator ite);
		int		getNumberOfElements(void);
		int		getMinValue();
		int		getMaxValue();
		void	displayElements(void);

		class	MaxCapacityException: public std::exception{
			public:
				const char * what() const throw();
		};
		class	NoSpanCanBeFoundException: public std::exception{
			public:
				const char* what() const throw ();	
		};
		class	EmptyClassException: public std::exception{
			public:
				const char * what() const throw();
		};
	private:
		unsigned int		_limit;
		std::vector<int>	_v;
};

#endif