/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:37:21 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:26:52 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
: AForm(src), _target(src._target){
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs){
	std::cout << "Copy assignment operator of ShrubberyCreationForm called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	checkRequirements(executor);
	std::string	outfile = _target;
	outfile += "_shrubbery";
	std::ofstream	ofs(outfile.c_str());
	if (!ofs.is_open())
		throw ShrubberyCreationForm::OutfileCantBeCreateException();
	drawTrees(ofs);
	return ;
}

void	ShrubberyCreationForm::checkRequirements(Bureaucrat const& executor) const{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else
		return ;
}

void	ShrubberyCreationForm::drawTrees(std::ofstream& ofs) const{
	ofs << " ^   ^   ^" << std::endl;
	ofs << "^^^ ^^^ ^^^" << std::endl;
	ofs << "^^^ ^^^ ^^^" << std::endl;
	ofs << " |   |   |" << std::endl;
	ofs << " |   |   |" << std::endl;
	ofs << "-----------" << std::endl;
	ofs.close();
	return ;
}

const char* ShrubberyCreationForm::OutfileCantBeCreateException::what() const throw(){
	return ("the shrubbery file cannot be opened");
}