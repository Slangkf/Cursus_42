/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:37:50 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/17 09:27:58 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack<T>(void);
		MutantStack<T>(MutantStack<T> const& src);
		~MutantStack<T>();
		MutantStack<T>&	operator=(MutantStack<T> const& rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif