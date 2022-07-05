/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:21:51 by shaas             #+#    #+#             */
/*   Updated: 2022/07/05 20:58:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

void	useMegaphone(char *sentence){
	for(size_t i = 0; i < std::strlen(sentence); i++) {
		std::cout << (char)std::toupper(sentence[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return(0);
	}
	for(int i = 1; argv[i] != NULL; i++) {
		useMegaphone(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}