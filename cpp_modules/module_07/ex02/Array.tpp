/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:53:03 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/10 12:17:44 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void): _array(NULL), _size(0){
//	std::cout << "Default constructor of Array called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){
//	std::cout << "Constructor of Array with an integer parameter called" << std::endl;
}

template<typename T>
Array<T>::Array(Array const& src): _array(new T[src.size()]), _size(src.size()){
//	std::cout << "Copy constructor of Array called" << std::endl;
	for (unsigned int i = 0; i < src.size(); i++)
		this->_array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array(void){
//	std::cout << "Destructor of Array called" << std::endl;
	delete [] this->_array;
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const& rhs){
//	std::cout << "Assignment operator of Array called" << std::endl;
	if (this != &rhs){
		delete [] _array;
		this->_array = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); i++)
			this->_array[i] = rhs._array[i];
		this->_size = rhs.size();
	}
	return *this;
}

template<typename T>
T const&	Array<T>::operator[](unsigned int index) const{
	if (index >= this->_size)
		throw OutOfBoundsIndexException();
	else
		return this->_array[index];
}

template<typename T>
T&	Array<T>::operator[](unsigned int index){
	if (index >= this->_size)
		throw OutOfBoundsIndexException();
	else
		return this->_array[index];
}

template<typename T>
unsigned int	Array<T>::size(void) const{
	return this->_size;
}

template<typename T>
const char * Array<T>::OutOfBoundsIndexException::what () const throw(){
	return "Exception throwed: invalid index";
}