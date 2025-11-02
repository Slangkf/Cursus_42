/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:20:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:46:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void){
	std::cout << "We create an intern named Tobert" << std::endl;
	Intern	Tobert;
	std::cout << std::endl;

	std::cout << "Tobert are trying to create an invalid form" << std::endl;
	try {
		AForm*	form;
		form = Tobert.makeForm("unknow name", "test1");	
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Now, Tobert will create a valid form and a bureaucrat will execute it" << std::endl;
	try {
		Bureaucrat	Charles("Charles", 5);
		std::cout << Charles << std::endl;
		AForm*	form;
		form = Tobert.makeForm("shrubbery creation", "test2");
		std::cout << *form << std::endl;
		Charles.signForm(*form);
		Charles.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}