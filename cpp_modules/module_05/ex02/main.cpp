/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:20:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:29:36 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void){
	std::cout << "We create two Bureaucrats" << std::endl;
	Bureaucrat	Oliver("Oliver", 137);
	Bureaucrat	Mabel("Mabel", 5);
	std::cout << Oliver << std::endl;
	std::cout << Mabel << std::endl;
	std::cout << std::endl;

	std::cout << "We create a ShrubberyCreation form and Oliver will run it." << std::endl;
	ShrubberyCreationForm	scf("test");
	std::cout << scf << std::endl;
	Oliver.executeForm(scf);
	Oliver.signForm(scf);
	std::cout << scf << std::endl;
	Oliver.executeForm(scf);
	std::cout << std::endl;

	std::cout << "We create a RobotomyRequest form. Oliver and then Mabel try to run it." << std::endl;
	RobotomyRequestForm	rrf("test2");
	std::cout << rrf << std::endl;
	Oliver.executeForm(rrf);
	Oliver.signForm(rrf);
	std::cout << rrf << std::endl;
	Mabel.executeForm(rrf);
	Mabel.signForm(rrf);
	std::cout << rrf << std::endl;
	Mabel.executeForm(rrf); //must succeed 50% of the time.
	Mabel.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "We create a PresidentialPardon form and Mabel will run it." << std::endl;
	PresidentialPardonForm	ppf("test3");
	std::cout << ppf << std::endl;
	Mabel.executeForm(ppf);
	Mabel.signForm(ppf);
	std::cout << ppf << std::endl;
	Mabel.executeForm(ppf);
	std::cout << std::endl;
	return (0);
}