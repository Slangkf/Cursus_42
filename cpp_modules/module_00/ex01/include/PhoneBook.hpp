/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:36:44 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 11:35:28 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	displayPhoneBook(void);
	private :
		Contact	contact[8];
		int 	_nbContact;
		int		_olderContact;
		int		_currentContact;
};

#endif
