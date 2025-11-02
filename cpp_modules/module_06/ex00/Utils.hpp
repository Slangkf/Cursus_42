/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:46:11 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 10:46:42 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cfloat>

bool	isChar(std::string value);
bool	isInt(std::string value);
bool	isFloat(std::string value);
bool	isDouble(std::string value);

void	displayFromChar(std::string value);
void	displayFromInt(std::string value);
void	displayFromFloat(std::string value);
void	displayFromDouble(std::string value);
#endif