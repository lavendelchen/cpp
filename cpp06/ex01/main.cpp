/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 19:20:34 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <string>
#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int main(void) {
	Data data;
	data.someStuff = 50;
	data.theStuffsGotAName = "hello";
	uintptr_t raw = serialize(&data);
	Data* ptr = deserialize(raw);

	std::cout << &data << " || " << ptr;
	std::cout << "\nData members: " << data.someStuff << data.theStuffsGotAName;
	if (ptr == &data)
		std::cout << "\nIt worked!\n";
	else
		std::cout << "\nIt didn't work :(\n";
	return 0;
}
