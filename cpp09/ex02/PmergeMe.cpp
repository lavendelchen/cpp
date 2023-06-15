/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 19:01:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &orig) {
	(void)orig;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) { }
	return *this;
}

ValueData::ValueData() { }

ValueData::ValueData(ValueData* lower) {
	this->value = -1;
	this->higher = NULL;
	this->lower.push_back(lower);
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
PmergeMe::~PmergeMe() { }

/* -------------------------------- PRIVATE METHODS -------------------------------- */
void	PmergeMe::mergeMe_deque(char* input[]) {
	SortDeque	sequence;
	SortDeque	mainChain;

	inputParsing(input, sequence);
	printSequence("Before", sequence);
	if (true) {//!isSorted(sequence)) { // should we use? not sure
		std::cout << "IS NOT SORTED\n";
		FJMI(sequence, mainChain);
	}
	printSequence("After", mainChain);

	for (SortDeque::iterator i = sequence.begin(); i != sequence.end(); i++) {
		delete *i;
	}
}

void	PmergeMe::mergeMe_vector(char* input[]) {
	(void)input;
}

void	PmergeMe::inputParsing(char* input[], SortDeque& sequence) {
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
		for (SortDeque::iterator i = sequence.begin(); i != sequence.end(); i++) {
			if ((*i)->value == buffer)
				throw std::logic_error("Error: No duplicates please");
		}

		ValueData* newElement = new ValueData;
		newElement->value = buffer;
		newElement->higher = NULL;
		sequence.push_back(newElement);
	}
}

void	PmergeMe::FJMI(SortDeque& sequence, SortDeque& mainChain) { // need pair for mainChain?
	SortDeque	greaterSequence;
	ValueData*	oddLeftover;

	if (sequence.size() > 1) {
		makePairs(sequence, greaterSequence, oddLeftover); // put in if as well?
		//printData(sequence);
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

void	PmergeMe::makePairs(SortDeque& sequence, SortDeque& greaterSequence, ValueData*& oddLeftover) {
	SortDeque::iterator sortFirst = sequence.begin();
	SortDeque::iterator sortSecond = ++sequence.begin();
	SortDeque::iterator end;
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
			(*sortSecond)->higher = *sortFirst;
			greaterSequence.push_back(*sortFirst);
		}
		else {

			(*sortSecond)->lower.push_back((*sortFirst));
			(*sortFirst)->higher = *sortSecond;
			greaterSequence.push_back(*sortSecond);
		}
	}
}

void	PmergeMe::binaryInsert(SortDeque& mainChain, ValueData*& oddLeftover) {
	SortDeque	toSort = mainChain;
	ValueData	oddData(oddLeftover);
	if (oddLeftover != NULL) {
		toSort.push_back(&oddData);
	}
	std::cout << "\nMAIN CHAIN ";
	printData(mainChain);
	std::cout << "\nTO_SORT ";
	printData(toSort);

	int num = toSort.size();
	int	powerOfTwo = 2;
	int groupSize = 2;
	int firstIndex = 2;
	int	lastIndex = 3; // need all those variables?
	SortDeque::iterator	i;

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
		std::cout << " GROUP SIZE [" << groupSize << ']';
		lastIndex = firstIndex + groupSize - 1;
	}
	std::cout << '\n';
}

void	PmergeMe::binarySearch(SortDeque& mainChain, ValueData* higher, ValueData* toSort) {
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
		//std::cout << "SEGFAULTTTTTTTTTTTTTTTTT\n";
		if (toSort->value < mElement->value)
			higherIndex = mIndex - 1;
		else
			lowerIndex = mIndex;
	}
	if (toSort->value < mainChain[higherIndex]->value)
		mainChain.insert(mainChain.begin()+higherIndex, toSort);
	else
		mainChain.insert(mainChain.begin()+higherIndex+1, toSort);
	std::cout << "\nMAIN CHAIN ";
	printData(mainChain);
}

/* --> UTILS */

void	PmergeMe::printData(SortDeque& sequence) {
	for (SortDeque::iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout	<< "\n[" << (*i)->value << "]: "
					<< "HIGHER: " << ((*i)->higher == NULL? -1 : (*i)->higher->value)
					<< " LOWER: ";
		for (SortDeque::iterator j = (*i)->lower.begin(); j != (*i)->lower.end(); j++) {
			std::cout << (*j)->value << ' ';
		}
	}
	std::cout << '\n';
}

void	PmergeMe::printSequence(std::string printBefore, SortDeque& sequence) {
	std::cout << printBefore << ":	";
	for (SortDeque::const_iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << ' ' << (*i)->value;
		//std::cout << " \"" << (*i)->value << "\",";
	}
	std::cout << '\n';
}

bool	PmergeMe::isSorted(SortDeque& sequence) {
	SortDeque::const_iterator i = sequence.begin();
	SortDeque::const_iterator after_i = ++sequence.begin();
	SortDeque::const_iterator end = sequence.end();

	for (;after_i != end; i++, after_i++) {
		if ((*i)->value >= (*after_i)->value)
			return (false);
	}
	return (true);
}

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	PmergeMe::mergeMe(char* input[]) {
	//maybe do template or overload?
	mergeMe_deque(input);
	//mergeMe_vector(input);
	//std::cout << "Before:	";
	//for (int i = 0; input[i] != NULL; i++) {
	//	std::cout << input[i] << ' ';
	//}
	//std::cout << '\n';
}

ValueData*	ValueData::getNewestLower(void) {
	if (this->lower.empty())
		return (NULL);

	ValueData* newestLower = this->lower.back();
	this->lower.pop_back();
	return (newestLower);
}

/* -------------------------------- OVERLOADS -------------------------------- */

bool	ValueData::operator==(ValueData const &rhs) {
	if (this->value == rhs.value)
		return (true);
	return (false);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
