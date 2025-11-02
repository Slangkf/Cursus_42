/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:53:16 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 13:00:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

DataBase::DataBase(void){
	std::cout << "Default constructor of DataBase called" << std::endl;
	return ;
}

DataBase::DataBase(DataBase const& src){
	std::cout << "Copy constructor of DataBase called" << std::endl;
	(void)src;
	return ;
}

DataBase::~DataBase(){
	std::cout << "Destructor of DataBase called" << std::endl;
	return ;
}

DataBase&	DataBase::operator=(DataBase const& rhs){
	std::cout << "Assignment operator of DataBase called" << std::endl;
	(void)rhs;
	return *this;
}

const char * DataBase::CannotOpenDataBaseException::what() const throw(){
	return "Error: cannot open file data.csv";
}

const char * DataBase::InvalidContentCSVFileException::what() const throw(){
	return "Error: invalid content in data.csv file";
}

std::map<std::string, float> DataBase::_dataBase;

static void	extractLine(std::map<std::string, float>& dataBase, std::string& line){
	size_t		commaPos = line.find(',');
	std::string key = line.substr(0, commaPos);
	std::string	value = line.substr(commaPos + 1);
	dataBase[key] = strtof(value.c_str(), NULL);
}

static void	checkValue(std::string const& line){
	std::string::const_iterator	it = line.begin() + 11;
	std::string::const_iterator	ite = line.end();
	int	dot = 0;
	for (; it != ite; ++it){
		if (*it == '.')
			dot++;
		if (!isdigit(*it) && *it != '.')
			throw DataBase::InvalidContentCSVFileException();
	}
	if (dot > 1)
		throw DataBase::InvalidContentCSVFileException();
	std::string	tmp(line.begin() + 11, ite);
	double	value = atof(tmp.c_str());
	if (value < 0 || value > 66063.56)
		throw DataBase::InvalidContentCSVFileException();
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
			throw DataBase::InvalidContentCSVFileException();
		it = line.begin() + 5;
		ite = line.begin() + 7;
		std::string	month(it, ite);
		if (month < "01" || month > "12")
			throw DataBase::InvalidContentCSVFileException();
		it = line.begin() + 8;
		ite = line.begin() + 10;
		std::string	day(it, ite);
		if (day < "01" || day > dayLimit(year, month))
			throw DataBase::InvalidContentCSVFileException();
		it = line.begin();
		ite = line.begin() + 10;
		std::string	limit(it, ite);
		if (limit < "2009-01-02" || limit > "2022-03-29")
			throw DataBase::InvalidContentCSVFileException();
	}
	else
		throw DataBase::InvalidContentCSVFileException();
}

static void	checkFormat(std::string& line){
	if (!line.empty()) {
		std::string::const_iterator	it = line.begin();
		std::string::const_iterator	ite = line.end();
		if (std::count(it, ite, '-') != 2)
			throw DataBase::InvalidContentCSVFileException();
		if (std::count(it, ite, ',') != 1)
			throw DataBase::InvalidContentCSVFileException();
		if (std::count(it, ite, '.') > 1)
			throw DataBase::InvalidContentCSVFileException();
		if (line.at(4) != '-' || line.at(7) != '-')
			throw DataBase::InvalidContentCSVFileException();
		if (line.at(10) != ',')
			throw DataBase::InvalidContentCSVFileException();
		for (; it != ite; ++it){
			if (!isdigit(*it) && (*it != '-' && *it != ',' && *it != '.'))
				throw DataBase::InvalidContentCSVFileException();
		}	
	}
	else
		throw DataBase::InvalidContentCSVFileException();
}

static void checkLine(std::string& line){
	checkFormat(line);
	checkDate(line);
	checkValue(line);
}

std::map<std::string, float> const&	DataBase::_loadData(void){
	std::ifstream	ifs("data.csv");
	if (!ifs.is_open())
		throw CannotOpenDataBaseException();
	ifs.seekg(0, std::ios::end);
	std::streampos	pos = ifs.tellg();
	if (pos == 0)
		throw InvalidContentCSVFileException();
	ifs.seekg(0, std::ios::beg);
	std::string	line;
	bool		f_line = true;
	while (std::getline(ifs, line)){
		if (f_line && line != "date,exchange_rate")
			throw InvalidContentCSVFileException();
		else if (!f_line){
			checkLine(line);
			if (!line.empty() && line != "date,exchange_rate"){
				if (line[line.size() - 1] == '\r')
					line.erase(line.size() - 1);
				extractLine(_dataBase, line);
			}
		}
		f_line = false;
	}
	ifs.close();
	return _dataBase;
}

std::map<std::string, float> const&	DataBase::getDataBase(void){
	return _loadData();
}