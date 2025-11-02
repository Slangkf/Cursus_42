/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:09:55 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/30 10:30:06 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form{
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(Form const& src);
		~Form();
		Form&	operator=(Form const& rhs);

		std::string const&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		void				beSigned(Bureaucrat const& src);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException: public std::exception{
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

std::ostream&	operator<<(std::ostream& os, Form const& rhs);

#endif