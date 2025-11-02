/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:46:08 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 12:04:57 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool	isChar(std::string value){
	if (value.length() == 1 && isprint(value[0]) && !isdigit(value[0]))
		return true;
	else
		return false;
}

bool	isInt(std::string value){
	if (value.size() == 1 && !isdigit(value[0]))
		return false;
	if (value[0] != '+' && value[0] != '-' && !isdigit(value[0]))
			return false;
	for (size_t i = 1; i < value.length(); i++){
		if (!isdigit(value[i]))
			return false;
	}
	long tmp = strtol(value.c_str(), NULL, 10);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return false;
	else
		return true;
}

bool	isFloat(std::string value){
	if (value == "-inff" || value == "+inff" || value == "nanf")
		return true;
	if (value.find('.') == std::string::npos || value[value.length() - 1] != 'f')
		return false;
	int digitCount = 0;	int dotCount = 0; int fCount = 0;
	for (size_t i = 0; i < value.length(); i++){
		if (value[i] != '+' && value[i] != '-' && value[i] != '.'
			&& value[i] != 'f' && !isdigit(value[i]))
			return false;
		if (isdigit(value[i]))
			digitCount++;
		else if (value[i] == '.')
			dotCount++;
		else if (value[i] == 'f')
			fCount++;
	}
	if (digitCount < 1 || dotCount > 1 || fCount > 1)
		return false;
	else
		return true;
}

bool	isDouble(std::string value){
	if (value == "-inf" || value == "+inf" || value == "nan")
		return true;
	if (value.find('.') == std::string::npos)
		return false;
	int digitCount = 0;	int dotCount = 0;
	for (size_t i = 0; i < value.length(); i++){
		if (isdigit(value[i]))
			digitCount++;
		else if (value[i] == '.')
			dotCount++;
		if (value[i] != '+' && value[i] != '-'
			&& value[i] != '.' && !isdigit(value[i]))
			return false;
	}
	if (digitCount < 1 || dotCount > 1)
		return false;
	else
		return true;
}

void	displayFromChar(std::string value){
	char c = value[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	return ;
}

void	displayFromInt(std::string value){
	int	tmp = atoi(value.c_str());	
	if (tmp >= 32 && tmp <= 126)
		std::cout << "char: '"<< static_cast<char>(tmp) << "'" << std::endl;
	else if ((tmp >= 0 && tmp <= 31) || tmp == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << tmp << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
	return ;
}

void	displayFromFloat(std::string value){
	float	tmp = strtof(value.c_str(), NULL);
	if (std::isfinite(tmp) && (tmp >= 32 && tmp <= 126))
		std::cout << "char: '"<< static_cast<char>(tmp) << "'" << std::endl;
	else if (std::isfinite(tmp) && ((tmp >= 0 && tmp <= 31) || tmp == 127))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (std::isfinite(tmp) && (static_cast<long>(tmp) >= INT_MIN 
			&& static_cast<long>(tmp) <= INT_MAX))
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (std::isinf(tmp) && tmp > 0){
		std::cout << "float: +" << tmp << "f" << std::endl;
		std::cout << "double: +" << static_cast<double>(tmp) << std::endl;
	}
	else {
		std::cout << "float: " << tmp << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(tmp) << std::endl;
	}
	return ;
}

void	displayFromDouble(std::string value){
	double	tmp = strtod(value.c_str(), NULL);
	if (std::isfinite(tmp) && (tmp >= 32 && tmp <= 126))
		std::cout << "char: '"<< static_cast<char>(tmp) << "'" << std::endl;
	else if (std::isfinite(tmp) && ((tmp >= 0 && tmp <= 31) || tmp == 127))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (std::isfinite(tmp) && (static_cast<long>(tmp) >= INT_MIN 
			&& static_cast<long>(tmp) <= INT_MAX))
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (std::isinf(tmp) && tmp > 0){
		std::cout << "float: +" << tmp << "f" << std::endl;
		std::cout << "double: +" << static_cast<double>(tmp) << std::endl;
	}
	else {
		std::cout << "float: " << tmp << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(tmp) << std::endl;
	}
	return ;
}