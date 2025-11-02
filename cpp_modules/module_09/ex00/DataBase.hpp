/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:48:37 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:00:45 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

class DataBase{
	public:
		static std::map<std::string, float> const&	getDataBase();

		class CannotOpenDataBaseException: public std::exception{
			public:
				const char * what() const throw();	
		};
		class InvalidContentCSVFileException: public std::exception{
			public:
				const char * what() const throw();	
		};
	private:
		DataBase();
		DataBase(DataBase const& src);
		~DataBase();
		DataBase&	operator=(DataBase const& rhs);
		static std::map<std::string, float> const&	_loadData(void);
		static std::map<std::string, float>	_dataBase;
};

#endif