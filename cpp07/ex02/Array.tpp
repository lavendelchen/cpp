/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:34:39 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 23:51:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ------------------------------- CONSTRUCTOR --------------------------------*/
template <typename T>
Array<T>::Array(): arr(NULL), arrSize(0) { }

template <typename T>
Array<T>::Array(uint n): arrSize(n) {
	this->arr = new T[this->arrSize];
}

template <typename T>
Array<T>::Array(const Array &orig): arrSize(orig.arrSize) {
	arr = new T[this->arrSize];

	for (uint i = 0; i < this->arrSize; i++) {
		this->arr[i] = orig[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array &rhs) {
	if (this != &rhs) {
		delete[] this->arr;
		this->arrSize = rhs.size();
		this->arr = new T[this->arrSize];
		for (uint i = 0; i < this->arrSize; i++) {
			this->arr[i] = rhs[i];
		}
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
template <typename T>
Array<T>::~Array() {
	delete[] this->arr;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
template <typename T>
uint	Array<T>::size() const {
	return (this->arrSize);
}

/* --------------------------------- EXCEPTION METHODS --------------------------------- */
template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
	return ("Error: Index out of bounds");
}

/* --------------------------------- OVERLOAD --------------------------------- */

template <typename T>
T& Array<T>::operator[](uint index) {
	if (index >= this->arrSize) {
		throw (IndexOutOfBoundsException());
	}
	return (this->arr[index]);
}

template <typename T>
const T&	Array<T>::operator[](uint index) const {
	if (index >= this->arrSize) {
		throw (IndexOutOfBoundsException());
	}
	return (this->arr[index]);
}

template <typename T>
std::ostream&	operator<<(std::ostream &out, Array<T> &array) {
	uint	arrSize(array.size());

	out	<< "Size: " << arrSize << '\n';
	for (uint i = 0; i < arrSize; i++) {
		out << array[i] << ", ";
	}
	return (out);
}