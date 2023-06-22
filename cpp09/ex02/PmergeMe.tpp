/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2023/06/22 18:43:34 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

#include "PmergeMe.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
template <typename Sorter, typename ValueData>
PmergeMe<Sorter,ValueData>::PmergeMe() { }

template <typename Sorter, typename ValueData>
PmergeMe<Sorter,ValueData>::PmergeMe(const PmergeMe<Sorter,ValueData> &orig) {
	(void)orig;
}

template <typename Sorter, typename ValueData>
PmergeMe<Sorter,ValueData>&	PmergeMe<Sorter,ValueData>::operator=(const PmergeMe<Sorter,ValueData> &rhs) {
	if (this != &rhs) { }
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
template <typename Sorter, typename ValueData>
PmergeMe<Sorter,ValueData>::~PmergeMe() { }

/* -------------------------------- PRIVATE METHODS -------------------------------- */
template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::inputParsing(char* input[], Sorter& sequence) {
	std::stringstream	inputStream;

	long long	buffer;
	for (int i = 0, j; input[i] != NULL; i++) {
		for (j = 0; input[i][j] != '\0'; j++) {
			if (!std::isdigit(input[i][j]))
				throw std::logic_error("Error: Each argument should be a positive integer");
		}
		if (j > 10 || j <= 0)
			throw std::logic_error("Error: Either you gave a too big number or an empty string");
		inputStream.str(input[i]);
		inputStream >> buffer;
		inputStream.clear();

		if (buffer > INT_MAX)
			throw std::logic_error("Error: Integers must be in int range");
		for (typename Sorter::iterator i = sequence.begin(); i != sequence.end(); i++) {
			if ((*i)->value == buffer)
				throw std::logic_error("Error: No duplicates please");
		}

		ValueData* newElement = new ValueData;
		newElement->value = buffer;
		sequence.push_back(newElement);
	}
}

template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::FJMI(Sorter& sequence, Sorter& mainChain) {
	Sorter	greaterSequence;
	ValueData*	oddLeftover;

	if (sequence.size() > 1) {
		makePairs(sequence, greaterSequence, oddLeftover);
		FJMI(greaterSequence, mainChain);
	}
	else {
		mainChain.push_back(sequence[0]);
		return;
	}
	mainChain.insert(mainChain.begin(), mainChain[0]->getNewestLower());
	
	if (mainChain.size() > 2)
		binaryInsert(mainChain, oddLeftover);
}

template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::makePairs(Sorter& sequence, Sorter& greaterSequence, ValueData*& oddLeftover) {
	typename Sorter::iterator sortFirst = sequence.begin();
	typename Sorter::iterator sortSecond = ++sequence.begin();
	typename Sorter::iterator end;
	switch (sequence.size() % 2) {
		case 0:
			oddLeftover = NULL;
			end = sequence.end();
			break;
		case 1:
			oddLeftover = sequence.back();
			end = --sequence.end();
			break;
	}

	for (; sortFirst != end; sortFirst+=2, sortSecond+=2) {
		if ((*sortFirst)->value > (*sortSecond)->value) {
			(*sortFirst)->lower.push_back((*sortSecond));
			greaterSequence.push_back(*sortFirst);
		}
		else {
			(*sortSecond)->lower.push_back((*sortFirst));
			greaterSequence.push_back(*sortSecond);
		}
	}
}

template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::binaryInsert(Sorter& mainChain, ValueData*& oddLeftover) {
	Sorter	toSort = mainChain;
	ValueData	oddData(oddLeftover);
	if (oddLeftover != NULL) {
		toSort.push_back(&oddData);
	}
	//std::cout << "\nMAIN CHAIN ";
	//printData(mainChain);
	//std::cout << "\nTO_SORT ";
	//printData(toSort);

	int num = toSort.size();
	int	powerOfTwo = 2;
	int groupSize = 2;
	int firstIndex = 2;
	int	lastIndex = 3;
	typename Sorter::iterator	i;

	while (firstIndex < num) {
		if (lastIndex >= num)
			lastIndex = num-1;

		i = toSort.begin()+lastIndex;
		for (;lastIndex >= firstIndex; lastIndex--, i--) {
			if ((*i)->value == -1)
				binarySearch(mainChain, NULL, (*i)->getNewestLower());
			else
				binarySearch(mainChain, *i, (*i)->getNewestLower());
		}

		firstIndex+=groupSize;
		powerOfTwo*=2;
		groupSize = powerOfTwo - groupSize;
		lastIndex = firstIndex + groupSize - 1;
	}
}

template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::binarySearch(Sorter& mainChain, ValueData* higher, ValueData* toSort) {
	int			higherIndex;
	if (higher == NULL)
		higherIndex = mainChain.size()-1;
	else
		higherIndex = std::find(mainChain.begin(), mainChain.end(), higher) - mainChain.begin();

	int			lowerIndex	= 0;
	int			mIndex;
	ValueData*	mElement;

	while (higherIndex != lowerIndex) {
		mIndex = ((higherIndex + lowerIndex) / 2) + ((higherIndex + lowerIndex) % 2);
		mElement = mainChain[mIndex];
		if (toSort->value < mElement->value)
			higherIndex = mIndex - 1;
		else
			lowerIndex = mIndex;
	}
	if (toSort->value < mainChain[higherIndex]->value)
		mainChain.insert(mainChain.begin()+higherIndex, toSort);
	else
		mainChain.insert(mainChain.begin()+higherIndex+1, toSort);
	//std::cout << "\nMAIN CHAIN BINARY";
	//printData(mainChain);
}

/* --> UTILS */
template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::printData(Sorter& sequence) {
	for (typename Sorter::iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << "\n[" << (*i)->value << "]: " << " LOWER: ";
		for (typename Sorter::iterator j = (*i)->lower.begin(); j != (*i)->lower.end(); j++) {
			std::cout << (*j)->value << ' ';
		}
	}
	std::cout << '\n';
}

template <typename Sorter, typename ValueData>
void	PmergeMe<Sorter,ValueData>::printSequence(std::string printBefore, Sorter& sequence) {
	std::cout << printBefore << ":	";
	for (typename Sorter::const_iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << ' ' << (*i)->value;
		//std::cout << " \"" << (*i)->value << "\",";
	}
	std::cout << '\n';
}

template <typename Sorter, typename ValueData>
bool	PmergeMe<Sorter,ValueData>::isSorted(Sorter& sequence) {
	typename Sorter::const_iterator i = sequence.begin();
	typename Sorter::const_iterator after_i = ++sequence.begin();
	typename Sorter::const_iterator end = sequence.end();

	for (;after_i != end; i++, after_i++) {
		if ((*i)->value >= (*after_i)->value)
			return (false);
	}
	return (true);
}

template <typename Sorter, typename ValueData>
unsigned long	PmergeMe<Sorter,ValueData>::calculateTsToNsec(timespec ts)
{
	unsigned long	nsec;

	nsec = ts.tv_sec;
	nsec *= 1000000000;
	nsec = nsec + ts.tv_nsec;
	return (nsec);
}

template <typename Sorter, typename ValueData>
unsigned long	PmergeMe<Sorter,ValueData>::getCurrTime(void)
{
	timespec	ts;

	if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
		throw std::logic_error("clock_gettime not working properly :(");
	return (calculateTsToNsec(ts) / 1000);
}

/* -------------------------------- PUBLIC METHODS -------------------------------- */
template <typename Sorter, typename ValueData>
unsigned long	PmergeMe<Sorter,ValueData>::mergeMe(char* input[], bool print) {
	unsigned long startTime = getCurrTime();
	
	Sorter	sequence;
	Sorter	mainChain;

	inputParsing(input, sequence);
	if (print)
		printSequence("Before", sequence);
	if (!isSorted(sequence)) {
		FJMI(sequence, mainChain);
		if (print)
			printSequence("After", mainChain);
	}
	else {
		if (print)
			printSequence("After", sequence);
	}

	for (typename Sorter::iterator i = sequence.begin(); i != sequence.end(); i++) {
		delete *i;
	}
	return (getCurrTime() - startTime);
}

/* -------------------------------- OVERLOADS -------------------------------- */

/* -------------------------------- EXCEPTION METHODS -------------------------------- */

#endif