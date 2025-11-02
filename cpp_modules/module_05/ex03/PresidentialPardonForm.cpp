/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:07:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:37:39 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src):
AForm(src), _target(src._target){
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs){
	std::cout << "Copy assignment operator of PresidentialPardonForm called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	checkRequirements(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return ;
}

void	PresidentialPardonForm::checkRequirements(Bureaucrat const& executor) const{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else
		return ;
}