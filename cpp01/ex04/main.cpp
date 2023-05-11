/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:48:50 by shaas             #+#    #+#             */
/*   Updated: 2023/05/11 21:45:49 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

enum argvNums {
	FILENAME = 1,
	S1 = 2,
	S2 = 3
} ;

bool	argCheck(int argc) {
	if (argc > 4 || argc < 4) {
		cerr	<< "\e[31mError: Wrong number of arguments!\e[0m\n"
					<< "\e[1mUsage: ./SedIsForLosers <filename> <s1> <s2>\e[0m"
					<< endl;
		return (true);
	}
	return (false);
}

bool	readFile(char *fileName, string& fileContent) {
	ifstream	fileStream(fileName);
	if (fileStream.is_open() == false) {
		cerr	<< "\e[31mError: " << fileName
					<< " couldn't be opened\e[0m" << endl;
		return (true);
	}

	stringstream	fileStringStream;
	fileStringStream << fileStream.rdbuf();
	fileContent = fileStringStream.str();
	return (false);
}

void	replaceString(string& fileContent, char *argv[]) {
	string	s1 = argv[S1];
	string	s2 = argv[S2];
	size_t		s1Pos;

	while (true) {
		s1Pos = fileContent.find(s1);
		if (s1Pos == string::npos)
			break ;
		fileContent.erase(s1Pos, s1.length());
		fileContent.insert(s1Pos, s2);
	}
}

void createReplaceFile(string& fileContent, char *fileName) {
	string	replaceFileName;
	replaceFileName = fileName;
	replaceFileName += ".replace";

	ofstream replaceStream(replaceFileName.c_str());
	replaceStream << fileContent;
	replaceStream.close();
}

int	main(int argc, char *argv[]) {
	if (argCheck(argc) == true)
		return (1);

	string fileContent;
	if (readFile(argv[FILENAME], fileContent) == true)
		return (1);
	replaceString(fileContent, argv);
	createReplaceFile(fileContent, argv[FILENAME]);
	return (0);
}
