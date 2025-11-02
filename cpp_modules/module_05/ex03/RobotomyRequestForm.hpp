/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:15:08 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:38:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
		
		void	checkRequirements(Bureaucrat const& executor) const;
		void	execute(Bureaucrat const & executor) const;

		class	RobotomyFailedException: public std::exception{
			public:
				const char* what() const throw();	
		};
	private:
		std::string	_target;
		mutable int	_robotomyCount;
};

#endif