/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:20:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/02 09:12:01 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void){
	std::cout << "We create two Bureaucrats" << std::endl;
	Bureaucrat	Charles("Charles", 70);
	Bureaucrat	Mabel("Mabel", 4);
	std::cout << Charles << std::endl;
	std::cout << Mabel << std::endl;
	std::cout << std::endl;

	std::cout << "We create two forms" << std::endl;
	Form	a("B22A", 1, 150);
	Form	b("C17B", 70, 120);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << "We try to create an invalid form" << std::endl;
	try {
		Form	c("X", 0, 150);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Bureaucrats try to sign forms" << std::endl;
	Charles.signForm(a);
	std::cout << a << std::endl;
	std::cout << std::endl;

	Mabel.signForm(b);
	std::cout << b << std::endl;
	Charles.signForm(b);
	std::cout << b << std::endl;
	std::cout << std::endl;
	return (0);
}