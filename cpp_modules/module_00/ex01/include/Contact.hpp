/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:36:38 by tclouet           #+#    #+#             */
/*   Updated: 2025/08/15 14:04:42 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

class Contact
{
	public :
		Contact(void);
		~Contact(void);
		void	fillContactFields(void);
		void	displayContacts(void) const;
		void	displayChosenContact(void) const;
	private :
		std::string	fName;
		std::string	lName;
		std::string	nName;
		std::string	pNumber;
		std::string	dSecret;
};

#endif
