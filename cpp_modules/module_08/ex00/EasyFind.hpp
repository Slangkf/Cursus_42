/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:05:50 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/14 14:13:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class	NoOccurenceException : public std::exception{
	const char * what() const throw();
};

const char * NoOccurenceException::what() const throw(){
	return "Exception thrown: no occurrence found";
}

template<typename T>
typename T::const_iterator	easyFind(T const& x, int y){
	typename T::const_iterator	it;
	it = std::find(x.begin(), x.end(), y);
	if (it == x.end())
		throw NoOccurenceException();
	else
		return it;
}

#endif