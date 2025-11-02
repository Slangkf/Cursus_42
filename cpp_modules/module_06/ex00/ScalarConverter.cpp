/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:06 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/06 15:59:17 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter(void){
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src){
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void){
	return ;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& rhs){
	(void)rhs;
	return *this;
}

void	ScalarConverter::convert(std::string value){
	if (value.empty()){
		std::cout << "Error: must be ./converter <argument>" << std::endl;
		return ;	
	}
	else if (isChar(value))
		displayFromChar(value);
	else if (isInt(value))
		displayFromInt(value);
	else if (isFloat(value))
		displayFromFloat(value);
	else if (isDouble(value))
		displayFromDouble(value);
	else
		std::cout << "The argument must be a char, an int, a float or a double" << std::endl;
	return ;
}
