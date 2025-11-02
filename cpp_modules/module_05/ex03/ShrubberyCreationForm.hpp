/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:37:25 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:38:30 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class ShrubberyCreationForm: public AForm{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);

		void	checkRequirements(Bureaucrat const& executor) const;
		void		execute(Bureaucrat const & executor) const;
		void		drawTrees(std::ofstream& ofs) const;

		class	OutfileCantBeCreateException: public std::exception{
			public :
				virtual const char* what() const throw();
		};
	private:
		std::string	_target;
};

#endif