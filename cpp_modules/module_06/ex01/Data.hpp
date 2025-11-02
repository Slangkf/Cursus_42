/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:44:52 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/07 14:52:14 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data{
	public:
		Data(int x, std::string y, bool z);
		Data(Data const& src);
		~Data();
		Data& operator=(Data const& rhs);
		
		int			getInt(void);
		std::string	getString(void);
		std::string	getBool(void);
	private:
		int			_x;
		std::string	_y;
		bool		_z;
};

#endif