/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/10 13:34:53 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	displayChar(char const& s){displayElement(s);}	//Wrapper functions used to call
void	changeChar(char& s){changeElement(s);}			//our template functions with iter().

int main(void){
	std::cout << "First, we create an array of integers and display it" << std::endl;
	int		array[] = {1, 2, 3, 4, 5};
	size_t	len = sizeof(array)/sizeof(array[0]);
	::iter(array, len, displayElement<int>);//Direct instantiation: we specify the template type.
	std::cout << std::endl;
	std::cout << "And then, we change all its values to 90" << std::endl;
	::iter(array, len, changeElement<int>);
	::iter(array, len, displayElement<int>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Next, we create an array of characters and display it" << std::endl;
	char	array2[] = {'A', 'B', 'C', 'D', 'E'};
	size_t	len2 = sizeof(array2)/sizeof(array2[0]);
	::iter(array2, len2, displayChar);
	std::cout << std::endl;
	std::cout << "Then, we change all characters to the letter Z" << std::endl;
	::iter(array2, len2, changeChar);
	::iter(array2, len2, displayChar);
	return 0;
}
