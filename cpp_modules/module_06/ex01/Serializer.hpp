/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:33:01 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 14:30:00 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

class Data;

class Serializer{
	public:
		static	uintptr_t	serialize(Data *ptr);
		static	Data*	deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(Serializer const& src);
		~Serializer();
		Serializer&	operator=(Serializer const& rhs);
};

#endif