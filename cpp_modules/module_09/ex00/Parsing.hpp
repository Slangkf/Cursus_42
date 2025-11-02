/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:43:40 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/22 11:27:06 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

#include <exception>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>

class InvalidInputException: public std::exception {
	public:
		const char * what() const throw ();
};

class CannotOpenInfileException: public std::exception {
	public:
		const char * what() const throw ();
};

class EmptyFileException: public std::exception {
	public:
		const char * what() const throw ();
};

class InvalidFileFormatException: public std::exception {
	public:
		const char * what() const throw ();
};

class OutOfRangeYearException: public std::exception {
	public:
		virtual const char * what() const throw ();
};

class OutOfRangeMonthException: public std::exception {
	public:
		const char * what() const throw ();
};

class OutOfRangeDayException: public std::exception {
	public:
		const char * what() const throw ();
};

class OutOfRangeCSVException: public std::exception {
	public:
		const char * what() const throw ();
};

void	checkInput(int argc, char **argv);
void	checkLine(std::string const& infile);

#endif