/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:43:40 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 12:45:16 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <cstdlib>

class RPN {
	public:
		static void	checkInput(int argc, char *argv);
		static void	doOperation(char *argv);

		class InvalidInputException: public std::exception{
			public:
				const char * what() const throw();	
		};
	private:
		RPN(void);
		RPN(RPN const& src);
		~RPN();
		RPN&	operator=(RPN const& src);
};

#endif
