/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:15:10 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:25:44 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_robotomyCount = 0;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src):
AForm(src), _target(src._target){
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs){
	std::cout << "Copy assignment operator of RobotomyRequestForm called" << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkRequirements(executor);
	if (this->_robotomyCount % 2 == 0){
		std::cout << "BZZZZZZZZZZZZZZ" << std::endl;
		std::cout << this->_target << " has been robotomized !" << std::endl;
		this->_robotomyCount++;
	}
	else {
		this->_robotomyCount++;
		throw RobotomyFailedException();
	}
	return ;
}

void	RobotomyRequestForm::checkRequirements(Bureaucrat const& executor) const{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else
		return ;
}

const char *	RobotomyRequestForm::RobotomyFailedException::what() const throw(){
	return ("robotomy has failed.");
}
