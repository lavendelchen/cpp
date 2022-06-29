/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:21:51 by shaas             #+#    #+#             */
/*   Updated: 2022/06/30 01:37:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

void	useMegaphone(char *sentence){
	for(int i = 0; sentence[i] != 0; i++) {
		if (sentence[i] >= 'a' && sentence[i] <= 'z')
			sentence[i] -= 32;
		std::cout << sentence[i];
	}
}

int main(int argc, char *argv[])
{
	if (argc <= 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return(0) ;
	}

	for(int i = 1; argv[i] != NULL; i++) {
		char	*sentence = argv[i];
		int		j;

		for(j = 0; sentence[j] != 0; j++) {
			if (sentence[j] >= 'a' && sentence[j] <= 'z')
				sentence[j] -= 32;
			std::cout << sentence[j];
		}
		if (argv[i + 1] != NULL && sentence[j - 1] != ' ' && argv[i + 1][0] != ' ')
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}