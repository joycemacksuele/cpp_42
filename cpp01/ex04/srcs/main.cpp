/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/04 07:56:00 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/Replace.hpp"
#include <string>
#include <iostream>
#include <new>
#include <unistd.h>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


/*
 * You are allowed to use everything in the standard library. HOWEVER, it
 * would be smart to try and use the C++-ish versions of the functions you
 * are used to in C, instead of just keeping to what you know, this is a new
 * language after all.
 * ----------------------------------------------------------------------------
 * -> Do not use the C file manipulation functions (e.g. fopen, fscanf, fgets,
 *    fprintf, fputs, fseek, rewind, fclose, getline).
 * -> Instead C++98 file stream library (<fstream>) can be used or the system
 *  call file control libraris <fcntl.h> and <sys/uio.h> (open, readv, writev).
 * ----------------------------------------------------------------------------
 * All the member functions of the class std::string are allowed, except replace.
 */


void	copyReplace(std::fstream &newFile, std::string line, std::string s1, std::string s2) {
	size_t	linePos = 0;
	size_t	i = 0;

	if (line.find(s1, linePos) == std::string::npos) {
		newFile << line << std::endl;
		continue ;
	}
	while ((linePos = line.find(s1, i)) != std::string::npos) {
		while (i < linePos) {
			newFile << line[i];
			i++;
		}
		for (size_t j = 0; j < s2.size(); j++) {// putitng s2 in line
			newFile << s2[j];
		}
		i = i + s1.size();
	}
	while (i < line.size()) {
		newFile << line[i];
		i++;
	}
}

void	openReadCopyReplaceFile(std::string fileName, std::string s1, std::string s2) {
	std::string		newFileName;
	std::fstream	file;
	std::fstream	newFile;
	std::string		line;

	file.open(fileName, std::fstream::in);// in for reading
	if (file.is_open()) {
		newFileName = fileName + ".replace";
		newFile.open(newFileName, std::fstream::out);// out for writing
		if (newFile.is_open()) {
			while (std::getline(file, line)) {
				copyReplace(newFile, line, s1, s2);

			/*	linePos = 0;
				i = 0;
				if (line.find(s1, linePos) == std::string::npos) {
					newFile << line << std::endl;
					continue ;
				}
				while ((linePos = line.find(s1, i)) != std::string::npos) {
					while (i < linePos) {
						newFile << line[i];
						i++;
					}
					for (size_t j = 0; j < s2.size(); j++) {// putitng s2 in line
						newFile << s2[j];
					}
					i = i + s1.size();
				}
				while (i < line.size()) {
					newFile << line[i];
					i++;
				}*/
				newFile << std::endl;
			}
		}
	}
	file.close();
	newFile.close();
}

bool	errorRandling(std::string fileName, std::string s1, std::string s2) {
	if (s1.empty() || s2.empty() || fileName.empty()) {
		std::cout << "strings can not be empty! Please try again" << std::endl;
		return true;
	}
	return false;
}

int		main(int argc, char **argv) {
	if (argc == 4) {
		if (errorRandling(argv[1], argv[2], argv[3])) {
			return -1;
		}
		openReadCopyReplaceFile(argv[1], argv[2], argv[3]);
	}
	std::cout << "<original file name> <s1> <s2> are needed as arguments!" << std::endl;
	return 0;
}
