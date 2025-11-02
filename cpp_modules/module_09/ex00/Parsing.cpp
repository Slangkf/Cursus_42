/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:45:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 10:27:14 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"

const char * InvalidInputException::what() const throw(){
	return "Error: input must be ./btc <name_of_file.txt>"; 
}

const char * CannotOpenInfileException::what() const throw(){
	return "Error: cannot open input file";
}

const char * EmptyFileException::what() const throw(){
	return "Error: input file is empty";
}

const char * InvalidFileFormatException::what() const throw(){
	return "Error: line format must be <YYYY-MM-DD | 0-1000>"; 
}

const char * OutOfRangeYearException::what() const throw(){
	return "Error: year must be between 2009 and 2022"; 
}

const char * OutOfRangeMonthException::what() const throw(){
	return "Error: invalid month"; 
}

const char * OutOfRangeDayException::what() const throw(){
	return "Error: invalid day"; 
}

const char * OutOfRangeCSVException::what() const throw(){
	return "Error: date must be between 2009-01-02 and 2022-03-29"; 
}

static void	checkValue(std::string const& line){
	std::string::const_iterator	it = line.begin() + 13;
	std::string::const_iterator	ite = line.end();
	int	dot = 0;
	for (; it != ite; ++it){
		if (*it == '.')
			dot++;
		if (!isdigit(*it) && *it != '.')
			throw InvalidFileFormatException();
	}
	if (dot > 1)
		throw InvalidFileFormatException();
	std::string	tmp(line.begin() + 13, ite);
	float	value = atof(tmp.c_str());
	if (value < 0 || value > 1000)
		throw InvalidFileFormatException();
}

static std::string	dayLimit(std::string const& year, std::string const& month){
	if (month == "02" && (year != "2012" && year != "2016" && year != "2020"))
		return "28";
	else if (month == "02" && (year == "2012" || year == "2016" || year == "2020"))
		return "29";
	else if (month == "04" || month == "06" || month == "09" || month == "11")
		return "30";
	else
		return "31";
}

static void	checkDate(std::string const& line){
	if (line.size() >= 10){
		std::string::const_iterator	it = line.begin();
		std::string::const_iterator	ite = line.begin();
		ite = line.begin() + 4;
		std::string	year(it, ite);
		if (year < "2009" || year > "2022")
			throw OutOfRangeYearException();
		it = line.begin() + 5;
		ite = line.begin() + 7;
		std::string	month(it, ite);
		if (month < "01" || month > "12")
			throw OutOfRangeMonthException();
		it = line.begin() + 8;
		ite = line.begin() + 10;
		std::string	day(it, ite);
		if (day < "01" || day > dayLimit(year, month))
			throw OutOfRangeDayException();
		it = line.begin();
		ite = line.begin() + 10;
		std::string	limit(it, ite);
		if (limit < "2009-01-02" || limit > "2022-03-29")
			throw OutOfRangeCSVException();
	}
	else
		throw InvalidFileFormatException();
}

static void checkFormat(std::string const& line){
	if (!line.empty()) {
		std::string::const_iterator	it = line.begin();
		std::string::const_iterator	ite = line.end();
		if (std::count(it, ite, '-') != 2)
			throw InvalidFileFormatException();
		if (std::count(it, ite, ' ') != 2)
			throw InvalidFileFormatException();
		if (std::count(it, ite, '|') != 1)
			throw InvalidFileFormatException();
		if (std::count(it, ite, '.') > 1)
			throw InvalidFileFormatException();
		if (line.at(4) != '-' || line.at(7) != '-')
			throw InvalidFileFormatException();
		if (line.at(10) != ' ' || line.at(12) != ' ')
			throw InvalidFileFormatException();
		if (line.at(11) != '|')
			throw InvalidFileFormatException();
		for (; it != ite; ++it){
			if (!isdigit(*it) && (*it != '-' && *it != ' ' &&
					*it != '|' && *it != '.'))
				throw InvalidFileFormatException();
		}	
	}
	else
		throw InvalidFileFormatException();
}

void	checkLine(std::string const& line){
	checkFormat(line);
	checkDate(line);
	checkValue(line);
}

void	checkInput(int argc, char **argv){
	if (argc != 2)
		throw InvalidInputException();
	std::string	input = argv[1];
	if (input.size() < 4 || input.compare((input.size() - 4), 4, ".txt"))
		throw InvalidInputException();
}
