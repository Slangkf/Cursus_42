/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:53:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/18 13:43:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define  BRAIN_HPP

#include <iostream>

class Brain{
    public:
        Brain(void);
        Brain(Brain const & src);
        ~Brain(void);
        Brain & operator=(Brain const & rhs);
    
        void        setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
    private:
        std::string _ideas[100];
};

#endif