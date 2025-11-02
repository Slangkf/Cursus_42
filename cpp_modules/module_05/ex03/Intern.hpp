/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:37:05 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/01 14:28:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class AForm;

class Intern{
	public:
		Intern();
		Intern(Intern const& src);
		~Intern();
		Intern&	operator=(Intern const& rhs);

		AForm*	makeForm(std::string name, std::string target) const;
		AForm*	createShrubberyForm(std::string target) const;
		AForm*	createRobotomyForm(std::string target) const;
		AForm*	createPresidentialForm(std::string target) const;
		void	displayMessage(int i) const;

		class	badFormNameException: public std::exception{
			public:
				const char * what() const throw ();
		};
};

#endif