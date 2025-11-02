/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:18:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/16 11:23:49 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int limit): _limit(limit){
//	std::cout << "Default constructor of Span called" << std::endl;
	return ;
}

Span::Span(Span const& src): _limit(src._limit), _v(src._v){
//	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Span::~Span(void){
//	std::cout << "Destructor of Span called" << std::endl;
	return ;
}

Span& Span::operator=(Span const& rhs){
//	std::cout << "Copy assignment operator of Span called" << std::endl;
	if (this != &rhs){
		this->_limit = rhs._limit;
		this->_v = rhs._v;
	}
	return *this;
}

const char * Span::MaxCapacityException::what() const throw(){
	return "Cannot add more numbers: the class is full";
}

const char * Span::NoSpanCanBeFoundException::what() const throw(){
	return "Value cannot be found: to few elements stored";
}

const char * Span::EmptyClassException::what() const throw(){
	return "Value cannot be found: the class is empty";
}

void	Span::addNumber(int value){
	if (_v.size() < _limit)
		_v.push_back(value);
	else
		throw MaxCapacityException();
}

void	Span::addMultipleNumbers(std::vector<int>::const_iterator it,
		std::vector<int>::const_iterator ite){
	if (it == ite)
		return ;
	else if (std::distance(it, ite) <= (static_cast<long>(_limit) -
				static_cast<long>(_v.size())))
		_v.insert(_v.end(), it, ite);
	else
		throw MaxCapacityException();
}

int	Span::shortestSpan(void){
	if (_v.size() == 0)
		throw EmptyClassException();
	else if (_v.size() == 1)
		throw NoSpanCanBeFoundException();
	else {
		std::vector<int> tmp = _v;
		std::vector<int>::iterator previous = tmp.begin();
		std::vector<int>::iterator current = previous + 1;
		std::vector<int>::iterator ite = tmp.end();
		std::sort(previous, ite);
		int	minDiff = INT_MAX;
		for (; current != ite; ++current){
			if ((*current - *previous) < minDiff)
				minDiff = (*current - *previous);
			previous = current;
		}
		return minDiff;
	}
}

int	Span::longestSpan(void){
	if (_v.size() == 0)
		throw EmptyClassException();
	else if (_v.size() == 1)
		throw NoSpanCanBeFoundException();
	else {
		int max = *std::max_element(_v.begin(), _v.end());
		int min = *std::min_element(_v.begin(), _v.end());
		return max - min;
	}
}

int	Span::getMinValue(void){
	if (_v.size() == 0)
		throw EmptyClassException();
	else
		return *std::min_element(_v.begin(), _v.end());
}

int	Span::getMaxValue(void){
	if (_v.size() == 0)
		throw EmptyClassException();
	else
		return *std::max_element(_v.begin(), _v.end());
}

int	Span::getNumberOfElements(void){
	return _v.size();
}

void	Span::displayElements(void){
	for (std::vector<int>::const_iterator it = _v.begin(); it != _v.end(); ++it)
		std::cout << *it << std::endl;
	return ;
}