/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:25:50 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/16 12:49:00 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void){
//	std::cout << "Default constructor of MutantStack called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& src): std::stack<T>(src){
//	std::cout << "Copy constructor of MutantStack called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack(){
//	std::cout << "Destructor of MutantStack called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const& rhs){
//	std::cout << "Copy assignment operator of MutantStack called" << std::endl;
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void){
	return this->c.end();
}