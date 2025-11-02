/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:45:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/30 12:46:51 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void){
	std::cout << "Default constructor of RPN called" << std::endl;
	return ;
}

RPN::RPN(RPN const& src){
	std::cout << "Copy constructor of RPN called" << std::endl;
	(void)src;
	return ;
}

RPN::~RPN(){
	std::cout << "Destructor of RPN called" << std::endl;
	return ;
}

RPN&	RPN::operator=(RPN const& rhs){
	std::cout << "Assignment operator of RPN called" << std::endl;
	(void)rhs;
	return *this;
}

const char *	RPN::InvalidInputException::what() const throw(){
	return "Error: invalid input";
}

static int	getValue(int left, char sign, int right){
	if (sign == '/' && right == 0)
		throw  RPN::InvalidInputException();
	else if (sign == '+')
		return left + right;
	else if (sign == '-')
		return left - right;
	else if (sign == '*')
		return left * right;
	else
		return left / right;
}

static bool	isOperator(char c){
	if (c != '+' && c != '-' &&
			c != '*' && c != '/' )
		return false;
	else
		return true;
}

void	RPN::doOperation(char *argv){
	std::stack<int>	stack;
	for (int i = 0; argv[i]; i++){
		if (isdigit(argv[i]))
			stack.push(argv[i] - 48);
		else if (isOperator(argv[i])){
			if (stack.size() < 2)
				throw InvalidInputException();
			else {
				char sign = argv[i];
				int	r_ope = stack.top();
				stack.pop();
				int l_ope = stack.top();
				stack.pop();
				stack.push(getValue(l_ope, sign, r_ope));
			}
		}
	}
	std::cout << stack.top() << std::endl;
}

void	RPN::checkInput(int argc, char *argv){
	if (argc != 2)
		throw InvalidInputException();
	else {
		int	digit_count = 0;
		int	operator_count = 0;

		for (int i = 0; argv[i]; i++){
			if (argv[i] != ' ' && !isOperator(argv[i]) && !isdigit(argv[i]))
				throw InvalidInputException();
			if (argv[i + 1] && (isdigit(argv[i]) && argv[i + 1] != 32))
				throw InvalidInputException();
			if (argv[i + 1] && (isOperator(argv[i]) && argv[i + 1] != 32))
				throw InvalidInputException();
			if (isdigit(argv[i]))
				digit_count++;
			if (isOperator(argv[i]))
				operator_count++;
		}
		if (!digit_count || !operator_count)
			throw InvalidInputException();
		if (digit_count != operator_count + 1)
			throw InvalidInputException();
	}
}