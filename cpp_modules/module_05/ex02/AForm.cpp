/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:09:52 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:22:43 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): 
_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	std::cout << "AForm default constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else
		_signed = false;
	return ;
}

AForm::AForm(AForm const& src):
_name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec){
	std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm::~AForm(void){
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

AForm&	AForm::operator=(AForm const& rhs){
	std::cout << "Copy assignment operator of AForm called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

std::string const&	AForm::getName(void) const{
	return this->_name;
}

bool	AForm::isSigned(void) const{
	return _signed;
}

int	AForm::getGradeToSign(void) const{
	return this->_gradeToSign;
}

int	AForm::getGradeToExec(void) const{
	return this->_gradeToExec;
}

void	AForm::beSigned(Bureaucrat const& src){
	if (src.getGrade() <= this->_gradeToSign && this->_signed == false)
		this->_signed = true;
	else if (src.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		throw AForm::FormAlreadySignedException();
	return ;
}

const char * AForm::GradeTooHighException::what() const throw(){
	return ("grade too high");
}

const char * AForm::GradeTooLowException::what() const throw(){
	return ("grade too low");
}

const char * AForm::FormNotSignedException::what() const throw(){
	return ("form not signed");
}

const char * AForm::FormAlreadySignedException::what() const throw(){
	return ("form already signed");
}

std::ostream&	operator<<(std::ostream& os, AForm const& rhs){
	os << "Form name: " << rhs.getName();
	if (rhs.isSigned())
		os << ", signed: yes";
	else
		os << ", signed: no";
	os << ", grade required to sign it: " << rhs.getGradeToSign();
	os << ", grade required to execute it: " << rhs.getGradeToExec();
	return os;
}