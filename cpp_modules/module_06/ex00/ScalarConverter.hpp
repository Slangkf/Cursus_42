/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/06 16:06:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter{
	public:
		static void	convert(std::string value);
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter();
		ScalarConverter&	operator=(ScalarConverter const& rhs);
};

#endif