/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:01:02 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"
#include "DataBase.hpp"

static void	converter(std::string& line, std::map<std::string,float> const& dataBase){
	std::string::iterator	it = line.begin();
	std::string::iterator	ite = line.begin() + 10;
	std::string	date(it, ite);

	std::string::iterator	it2 = line.begin() + 13;
	std::string::iterator	ite2 = line.end();
	std::string	number(it2, ite2);
	float	value = atof(number.c_str());
	
	std::map<std::string,float>::const_iterator	d_it = dataBase.begin();
	std::map<std::string,float>::const_iterator	d_ite = dataBase.end();
	std::cout << std::fixed;
	std::cout.precision(2);
	for (; d_it != d_ite; ++d_it){
		if (date == d_it->first){
			std::cout << date << " => " << number << " = " << value * d_it->second << std::endl;
			return ;
		}
	}
	for (d_it = dataBase.begin(); d_it != d_ite; ++d_it){
		if (date < d_it->first){
			--d_it;
			std::cout << date << " => " << number << " = " << value * d_it->second << std::endl;
			return ;
		}
	}
}

static void	exchange(char *infile, std::map<std::string,float> const& dataBase){
	std::string		line;
	std::ifstream	ifs(infile);
	if (!ifs.is_open())
		throw CannotOpenInfileException();
	ifs.seekg(0, std::ios::end);
	std::streampos	pos = ifs.tellg();
	if (pos == 0)
		throw EmptyFileException();
	ifs.seekg(0, std::ios::beg);
	bool	f_line = true;
	while (getline(ifs, line)){
		if (f_line && line != "date | value")
			std::cout << "Error: first line must be <date | value>"<< std::endl; 
		else if (!f_line){
			try {
				checkLine(line);
				converter(line, dataBase);
			}
			catch (std::exception& e){
				std::cout << e.what() << std::endl;
			}
		}
		f_line = false;
	}
}

int main(int argc, char **argv){
	try {
		checkInput(argc, argv);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		return -1;
	}
	try {
		std::map<std::string,float> const& dataBase = DataBase::getDataBase();
		exchange(argv[1], dataBase);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}
