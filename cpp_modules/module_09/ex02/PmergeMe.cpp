/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:10:57 by tclouet           #+#    #+#             */
/*   Updated: 2025/11/02 11:30:20 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){
	std::cout << "Default constructor of PmergeMe called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(PmergeMe const& src){
	std::cout << "Copy constructor of PmergeMe called" << std::endl;
	(void)src;
	return ;
}

PmergeMe::~PmergeMe(){
	std::cout << "Destructor of PmergeMe called" << std::endl;
	return ;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const& rhs){
	std::cout << "Assignment operator of PmergeMe called" << std::endl;
	(void)rhs;
	return *this;
}

// Perform a binary search to find the correct insertion position for "value".
static void	insertVectorValue(std::vector<int>& big, int value){
	int	start = 0;
	int	end = static_cast<int>(big.size() - 1);
	int middle = (start + end) / 2;
	while (start <= end) {
		if (value <= big[middle])
			end = middle - 1;
		else if (value > big[middle])
			start = middle + 1;
		middle = (start + end) / 2;
	}
	big.insert(big.begin() + start, value);
}

// Generate a Jacobsthal sequence to determine the order in which
// elements from the 'small' vector will be inserted into 'big'.
static std::vector<int>	getJacobsthalVector(int s_size){
	std::vector<int>	sequence;
	if (s_size == 1){
		sequence.push_back(0);
		return sequence;
	}
	sequence.push_back(0);
	sequence.push_back(1);
	for (int i = 2; i < s_size; i++){
			sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
			if (sequence.back() > s_size)
				break ;
	}
	return sequence;
}

// Insert elements from 'small' into 'big' according to the Jacobsthal sequence.
// 1: Insert elements at indexes defined by the Jacobsthal sequence.
// 2: Insert remaining elements (not yet inserted) in reverse order.
static void	insertSmallVector(std::vector<int>& big, std::vector<int>& small){
	int					s_size = static_cast<int>(small.size());
	std::vector<int>	j = getJacobsthalVector(s_size);
	std::vector<int>	used_index;
	for (int i = 0; i < s_size; i++){
		if (j[i] > s_size - 1)
			break ;
		std::vector<int>::iterator it;
		it = std::find(used_index.begin(), used_index.end(), j[i]);
		if (it == used_index.end()){
			insertVectorValue(big, small[j[i]]);
			used_index.push_back(j[i]);
		}
	}
	for (int i = s_size - 1; i > 0; i--){
		std::vector<int>::iterator it;
		it = std::find(used_index.begin(), used_index.end(), i);
		if (it == used_index.end())	
			insertVectorValue(big, small[i]);
	}
}

// Split 'v' into pairs of elements.
// The largest element of each pair goes into 'b', and the smallest into 's'.
// If 'v' has an odd size, the last unpaired element goes into 's'.
static void	sortVectorByPairs(std::vector<int>& v, std::vector<int>& big, std::vector<int>& small){
	for (size_t i = 0; i < v.size() - 1; i += 2) {
		if (v[i] >= v[i + 1]) {
			big.push_back(v[i]);
			small.push_back(v[i + 1]);
		}
		else {
			small.push_back(v[i]);
			big.push_back(v[i + 1]);
		}
	}
	if (v.size() % 2 != 0)
		small.push_back(v.back());
}

// Recursive sorting algorithm.
// 1. Split 'v' into two vectors: 'big' (largest values) and 'small' (smallest ones).
// 2. Recursively sort 'big'.
// 3. Insert all elements from 'small' into the sorted 'big' using Jacobsthal indices.
static void	vectorAlgorithm(std::vector<int>& vector){
	std::vector<int>	small;
	std::vector<int>	big;
	if (vector.size() == 1)
		return ;
	sortVectorByPairs(vector, big, small);
	vectorAlgorithm(big);
	insertSmallVector(big, small);
	vector = big;
}

void	PmergeMe::sortVector(char **argv, std::vector<int>& vector){
	fillContainer(argv, vector);
	vectorAlgorithm(vector);
}

static void	insertListValue(std::list<int>& big, int value){
	int	start = 0;
	int	end = static_cast<int>(big.size() - 1);
	int middle = (start + end) / 2;
	std::list<int>::iterator	itm = big.begin();
	std::advance(itm, middle);
	while (start <= end) {
		if (value <= *itm)
			end = middle - 1;
		else if (value > *itm)
			start = middle + 1;
		middle = (start + end) / 2;
		itm = big.begin();
		std::advance(itm, middle);
	}
	std::list<int>::iterator it = big.begin();
	std::advance(it, start);
	big.insert(it, value);
}

static std::list<int>	getJacobsthalList(std::list<int>& small){
	std::list<int>	sequence;
	int				s_size = small.size();
	if (s_size == 1){
		sequence.push_back(0);
		return sequence;
	}
	else {
		sequence.push_back(0);
		sequence.push_back(1);
		long						value;
		std::list<int>::iterator	current_it = sequence.begin();
		std::list<int>::iterator	next_it = sequence.begin();
		std::list<int>::iterator	list_ite = sequence.end();
		++next_it;
		while (next_it != list_ite){
			value = *next_it + 2 * *current_it;
			if (value >= s_size)
				break ;
			sequence.push_back(value);
			++next_it, ++current_it;
		}
		return sequence;
	}
}

static void	insertSmallList(std::list<int>& big, std::list<int>& small){
	std::list<int>				j = getJacobsthalList(small);
	std::list<int>::iterator	j_it = j.begin();
	std::list<int>::iterator	small_it = small.begin();
	std::list<int>::iterator	small_ite = small.end();
	std::list<int>				usedIndex;
	int							s_size = static_cast<int>(small.size());
	while (small_it != small_ite){
		if (*j_it > s_size)
			break ;
		std::list<int>::iterator it;
		it = std::find(usedIndex.begin(), usedIndex.end(), *j_it);
		if (it == usedIndex.end()){
			std::list<int>::iterator small_it2 = small.begin();
			std::advance(small_it2, *j_it);
			insertListValue(big, *small_it2);
			usedIndex.push_back(*j_it);
		}
		++small_it, ++j_it;
	}
	for (int i = s_size - 1; i > 0; i--){
		std::list<int>::iterator it;
		it = std::find(usedIndex.begin(), usedIndex.end(), i);
		if (it == usedIndex.end()){
			std::list<int>::iterator small_it3 = small.begin();
			std::advance(small_it3, i);
			insertListValue(big, *small_it3);
		}	
	}
}

static void	sortListByPairs(std::list<int>& list, std::list<int>& big, std::list<int>& small){
	std::list<int>::iterator	current_it = list.begin();
	std::list<int>::iterator	next_it = list.begin();
	std::list<int>::iterator	list_ite = list.end();
	++next_it;
	while (next_it != list_ite){
		if (*current_it >= *next_it){
			big.push_back(*current_it);
			small.push_back(*next_it);
		}
		else if (*current_it < *next_it){
			small.push_back(*current_it);
			big.push_back(*next_it);		
		}
		++next_it;
		if (next_it != list_ite)
			++next_it, ++current_it, ++current_it;
	}
	if (list.size() % 2 != 0)
		small.push_back(list.back());
}

static void	listAlgorithm(std::list<int>& list){
	std::list<int>	small;
	std::list<int>	big;

	if (list.size() == 1)
		return ;
	sortListByPairs(list, big, small);
	listAlgorithm(big);
	insertSmallList(big, small);
	list = big;
}

void	PmergeMe::sortList(char **argv, std::list<int>& list){
	fillContainer(argv, list);
	listAlgorithm(list);
}