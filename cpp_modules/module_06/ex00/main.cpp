/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:39:04 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 11:55:03 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Error: must be ./converter <argument>" << std::endl;
		return -1;
	}
	ScalarConverter::convert(std::string(argv[1]));
	return (0);
}