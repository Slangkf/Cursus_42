/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:09:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:21:31 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(AForm const& src);
		virtual ~AForm();
		AForm&	operator=(AForm const& rhs);

		std::string const&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		void				beSigned(Bureaucrat const& src);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class FormNotSignedException: public std::exception{
			public:
				virtual const char * what() const throw();	
		};
		class FormAlreadySignedException: public std::exception{
			public:
				virtual const char * what() const throw();	
		};
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream&	operator<<(std::ostream& os, AForm const& rhs);

#endif