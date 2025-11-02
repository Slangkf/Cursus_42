/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:20:14 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/01 10:27:54 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src._name), _grade(src._grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs){
	std::cout << "Copy assignment operator of Bureaucrat called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

const std::string&	Bureaucrat::getName(void) const{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void){
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void	Bureaucrat::decrementGrade(void){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
	return ;
}

void	Bureaucrat::signForm(AForm& src){
	try {
		src.beSigned(*this);
		std::cout << "Bureaucrat " << this->_name << " signed ";
		std::cout << src.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Bureaucrat " << this->_name;
		std::cout << " could not sign form " << src.getName();
		std::cout << ": " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const{
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << this->_name << " executed ";
		std::cout << form.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Bureaucrat " << this->_name << " cannot execute ";
		std::cout << form.getName() << " : ";
		std::cout << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return ("the grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return ("the grade is too low");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& rhs){
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}