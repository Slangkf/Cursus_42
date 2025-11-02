/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:09:52 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/30 14:17:33 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec): 
_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	std::cout << "Form default constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	else
		_signed = false;
	return ;
}

Form::Form(Form const& src):
_name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec){
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form::~Form(void){
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form&	Form::operator=(Form const& rhs){
	std::cout << "Copy assignment operator of Form called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

std::string const&	Form::getName(void) const{
	return this->_name;
}

bool	Form::isSigned(void) const{
	return _signed;
}

int	Form::getGradeToSign(void) const{
	return this->_gradeToSign;
}

int	Form::getGradeToExec(void) const{
	return this->_gradeToExec;
}

void	Form::beSigned(Bureaucrat const& src){
	if (src.getGrade() <= this->_gradeToSign && this->_signed == false)
		this->_signed = true;
	else if (src.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		throw Form::FormAlreadySignedException();
	return ;
}

const char * Form::GradeTooHighException::what() const throw(){
		return ("grade too high");
}

const char * Form::GradeTooLowException::what() const throw(){
	return ("grade too low");
}

const char * Form::FormAlreadySignedException::what() const throw(){
	return ("form already signed");
}

std::ostream&	operator<<(std::ostream& os, Form const& rhs){
	os << "Form name: " << rhs.getName();
	if (rhs.isSigned())
		os << ", signed: yes";
	else
		os << ", signed: no";
	os << ", grade required to sign it: " << rhs.getGradeToSign();
	os << ", grade required to execute it: " << rhs.getGradeToExec();
	return os;
}