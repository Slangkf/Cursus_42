/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/08 10:52:46 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

static Base*	generate(void){
	int	n = std::rand() % 3;
	switch (n){
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	std::cout << "Error in function generate()" << std::endl;
	return NULL;
}

static void	identify(Base *p){
	A*	a = dynamic_cast<A*>(p);
	if (a){
		std::cout << "The pointer points to an A object" << std::endl;
		return ;
	}
	B*	b = dynamic_cast<B*>(p);
	if (b){
		std::cout << "The pointer points to a B object" << std::endl;
		return ;
	}
	C*	c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "The pointer points to a C object" << std::endl;
		return ;
	}
	std::cout << "Error in function identify(*p)" << std::endl;
}

static void	identify(Base& p){
	try {
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The reference is an A object" << std::endl;
		return ;
	}
	catch (std::exception& bc){}
	try {
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "The reference is a B object" << std::endl;
		return ;
	}
	catch (std::exception& bc){}
	try {
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "The reference is a C object" << std::endl;
		return ;
	}
	catch (std::exception& bc){}
	std::cout << "Error in function identify(&p)" << std::endl;
}

int	main(void){
	std::srand(std::time(NULL));
	Base	*p;
	Base	*p2;
	Base	*p3;
	
	p = generate();
	identify(p);
	identify(*p);
	std::cout << std::endl;

	p2 = generate();
	identify(p2);
	identify(*p2);
	std::cout << std::endl;

	p3 = generate();
	identify(p3);
	identify(*p3);
	
	delete p;
	delete p2;
	delete p3;
	return (0);
}
