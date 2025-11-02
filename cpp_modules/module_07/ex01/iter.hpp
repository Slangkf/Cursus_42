/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:40:27 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/09 15:22:43 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>


template<typename T>
void	iter(T* array, size_t length, void (*f)(T&)){
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void	iter(T* array, size_t length, void (*f)(T const&)){
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename W>
void	displayElement(W const& element){
	std::cout << element << " ";
	return ;
}

template<typename W>
void	changeElement(W& element){
	element = 90;
	return ;
}

#endif