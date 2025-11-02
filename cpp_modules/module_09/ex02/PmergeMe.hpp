/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:11:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/11/02 10:58:48 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <iterator>
#include "Utils.hpp"

class PmergeMe {
	public:
		static void	sortVector(char **argv, std::vector<int>& v);
		static void	sortList(char **argv, std::list<int>& d);
	private :
		PmergeMe();
		PmergeMe(PmergeMe const& src);
		~PmergeMe();
		PmergeMe&	operator=(PmergeMe const& rhs);
};

#endif