/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:37:08 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/01 14:40:17 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const& src){
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void){
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern& Intern::operator=(Intern const& rhs){
	std::cout << "Copy assignment operator of Intern called" << std::endl;
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) const{
	std::string validName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreator[])(std::string) const = {&Intern::createShrubberyForm,
				&Intern::createRobotomyForm, &Intern::createPresidentialForm};
	int	i = 0;
	while (i < 3){
		if (validName[i] == name)
			break ;
		i++;
	}
	if (i == 3)
		throw Intern::badFormNameException();
	displayMessage(i);
	return (this->*formCreator[i])(target);
}

AForm*	Intern::createShrubberyForm(std::string target) const{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyForm(std::string target) const{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialForm(std::string target) const{
	return new PresidentialPardonForm(target);
}

void	Intern::displayMessage(int i) const{
	std::string formName[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	std::cout << "Intern creates " << formName[i] << std::endl;
}

const char*	Intern::badFormNameException::what() const throw(){
	return	"Unknown name, I cannot create the form !\n"
			"Please choose a name between: shrubbery creation,"
			" robotomy request or presidential pardon.";
}