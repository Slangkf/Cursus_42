/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:53:09 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/16 18:47:18 by tclouet          ###   ########.fr       */
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
        void        setIdeas(int index, const std::string& idea);
        std::string getIdeas(int index) const;
    private:
        std::string ideas[100];
};

#endif