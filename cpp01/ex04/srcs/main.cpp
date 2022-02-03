/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/03 07:59:53 by jfreitas         ###   ########.fr       */
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


void	copyReplace(std::string *line, std::string *copyLine, std::string &s1, std::string &s2) {
	size_t	copyLinePos = line->find(s1, 0);
	size_t	linePos = copyLinePos;
	size_t	i = 0;

	if (copyLinePos != std::string::npos) {
		copyLine->resize(line->size() + (s2.size() - s1.size()));
		while (copyLinePos < copyLine->size()) {
			while (i < s2.size()) {
				copyLine[copyLinePos] = s2[i];
				i++;
				copyLinePos++;
			}
			if ((linePos < line->find(s1, linePos + 1) && line->find(s1, linePos + 1) != std::string::npos) || line->find(s1, linePos + 1) == std::string::npos) {
				copyLine[copyLinePos] = line[linePos + s1.size()];
				linePos++;
			}
			copyLinePos++;
			if (line->find(s1, linePos) == linePos) {
				i = 0;
			}
		}
		i = 0;
		copyLinePos = line->find(s1, copyLinePos + 1);
	}
}

void	openReadCopyReplaceFile(std::string fileName, std::string s1, std::string s2) {
	std::string		newFileName;
	std::fstream	file;
	std::fstream	newFile;
	std::string		line;
	std::string		copyLine;

	size_t	copyLinePos;
	size_t	linePos;
	size_t	i = 0;

	file.open(fileName, std::fstream::in);// in for reading
	if (file.is_open()) {
		newFileName = fileName + ".replace";
		newFile.open(newFileName, std::fstream::out);// out for writing
		if (newFile.is_open()) {
			while (std::getline(file, line)) {
				copyLine = line;
				//copyReplace(&line, &copyLine, s1, s2);
				copyLinePos = line.find(s1, 0);
				linePos = copyLinePos;
				i = 0;
//
				while (copyLinePos != std::string::npos) {
					if (s1.size() != s2.size() && line.size() > 0) {
						copyLine.resize(line.size() + (s2.size() - s1.size()));
						std::cout << YELLOW << line.size() << " and " << copyLine.size() << std::endl << RESET;
					}
					//while (copyLinePos < copyLine.size()) {
					while (i < s2.size()) {
						copyLine[copyLinePos] = s2[i];
						i++;
						copyLinePos++;
					}
					if ((linePos < line.find(s1, copyLinePos) && line.find(s1, copyLinePos) != std::string::npos) || line.find(s1, copyLinePos) == std::string::npos) {
						copyLine[copyLinePos] = line[linePos + s1.size()];
						linePos++;
						copyLinePos++;
					}
					//copyLinePos++;
					if (line.find(s1, linePos) != std::string::npos) {
						i = 0;
						copyLinePos = line.find(s1, linePos);
					}
					std::cout << "i: " << i << std::endl;
				//	}
					//i = 0;
					//copyLinePos = line.find(s1, copyLinePos);
				}
//
				newFile << copyLine << std::endl;
			}
		}
	}
	file.close();
	newFile.close();
}

bool	errorRandling(std::string s1, std::string s2) {
	if (s1.empty() || s2.empty()) {
		std::cout << "strings can not be empty! Please try again" << std::endl;
		return true;
	}
	return false;
}

int		main(int argc, char **argv) {
	if (argc == 4) {
		if (errorRandling(argv[2], argv[3]))
			return -1;
		openReadCopyReplaceFile(argv[1], argv[2], argv[3]);
	}
	return 0;
}
