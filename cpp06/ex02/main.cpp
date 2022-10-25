/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 20:15:37 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <string>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum ABC {
	CASE_A,
	CASE_B,
	CASE_C
};

Base*	generate(void) {
	std::srand(time(NULL));
	int	ABC = std::rand() % 3;
	switch(ABC) {
		case CASE_A: std::cout << "A generated!\n";
			return new A();
		case CASE_B: std::cout << "B generated!\n";
			return new B();
		case CASE_C: std::cout << "C generated!\n";
			return new C();
	}
	return new Base();
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A detected\n"; return;
	}
	else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B detected\n"; return;
	}
	else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C detected\n"; return;
	}
	std::cout << "Huh?\n"; return;
}

void	identify(Base& p) {
	try { (void)(dynamic_cast<A &>(p)); }
	catch (std::bad_cast &) {
		try { (void)(dynamic_cast<B &>(p)); }
			catch (std::bad_cast &) {
				try { (void)(dynamic_cast<C &>(p)); }
					catch (std::bad_cast &) { 
						std::cout << "Huh?\n"; return;
					}
				std::cout << "C detected\n"; return;
			}
		std::cout << "B detected\n"; return;
	}
	std::cout << "A detected\n";
}

int	main(void) {
	Base*	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
