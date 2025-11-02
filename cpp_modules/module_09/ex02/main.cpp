/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:24:43 by tclouet           #+#    #+#             */
/*   Updated: 2025/11/02 11:12:55 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Algorithm inspired by: https://en.wikipedia.org/wiki/Merge-insertion_sort

#include "TimeManagement.hpp"
#include "Utils.hpp"
#include "PmergeMe.hpp"

static void	listAlgo(int argc, char **argv){
	TimeManagement::setStartTime();
	checkInput(argc, argv);
	displayUnsortedSequence(argv);
	std::list<int>	l;
	PmergeMe::sortList(argv, l);
	displaySortedSequence(l);
	TimeManagement::setEndTime();
	displayResult(TimeManagement::getDuration(), l, "std::list");
}

static void	vectorAlgo(int argc, char **argv){
	TimeManagement::setStartTime();
	checkInput(argc, argv);
	displayUnsortedSequence(argv);
	std::vector<int> vector;
	PmergeMe::sortVector(argv, vector);
	displaySortedSequence(vector);
	TimeManagement::setEndTime();
	displayResult(TimeManagement::getDuration(), vector, "std::vector");
}

int main(int argc, char **argv){
	try {
		vectorAlgo(argc, argv);
		listAlgo(argc, argv);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return -1;
	} 
	return 0;
}
