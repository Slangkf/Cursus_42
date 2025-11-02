/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:28 by tclouet           #+#    #+#             */
/*   Updated: 2025/10/14 08:46:47 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& x, T& y){
	T	tmp = x;
	x = y;
	y = tmp;
	return ;
}

template<typename U>
U const&	min(U const& x, U const& y){
	return (x < y ? x : y);
}

template<typename V>
V const&	max(V const& x, V const& y){
	return (x > y ? x : y);
}

#endif