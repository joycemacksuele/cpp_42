/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/28 18:16:59 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/Replace.hpp"
#include <string>
#include <iostream>
#include <new>
#include <unistd.h>
#include <fstream>

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


void	replace(std::string newFileName, std::string s1, std::string s2) {
	std::fstream	newFile;
	std::string		line;
	int				i;

	i = 0;
	newFile.open(newFileName, std::fstream::in);
	if (newFile.is_open()) {
		while (1) {
			std::cout << "test";
			if (newFile.eof())
				break ;
			std::getline(newFile, line);
			size_t linePos = line.find(s1);
			std::cout << "--" << linePos << std::endl;
			if (linePos != std::string::npos) {
				i = 0;
				while (linePos < line.size() && (line[linePos] != '\n' || line[linePos] != '\0')) {
					if (s2[i]) {
						std::cout << line[linePos] << "|" << s2[i] << std::endl;
						line[linePos] = s2[i];
						newFile << line;//something wrong here
					}
					i++;
					linePos++;
				}
				std::cout << line  << std::endl;
			}

		}
	}
	newFile.close();
}

std::string	openAndCopyFile(std::string fileName, std::string s1, std::string s2) {
	std::fstream	file;
	std::fstream	newFile;
	std::string		newFileName;
	std::string		line;
	std::string		copyLine;
	size_t			i = 0;
	size_t			lineSize;

	file.open(fileName, std::fstream::in);// in for reading
	if (file.is_open()) {
		newFileName = fileName + ".replace";
		newFile.open(newFileName, std::fstream::out);// | std::fstream::in);//in for reading and out for writing
		if (newFile.is_open()) {
			while (std::getline(file, line)) {
				copyLine = line;
				lineSize = line.size();
				size_t linePos = line.find(s1, 0);
				size_t copyLinePos = linePos;
				if (linePos != std::string::npos) {
					while (linePos < lineSize) {
						while (i < s2.size()) {
							copyLine[linePos] = s2[i];
							i++;
							linePos++;
						}
						if ((copyLinePos < line.find(s1, copyLinePos + 1) && line.find(s1, copyLinePos + 1) != std::string::npos) || line.find(s1, copyLinePos + 1) == std::string::npos) {
							copyLine[linePos] = line[copyLinePos + s1.size()];
							copyLinePos++;
							std::cout << "testinggg" << std::endl;
						}
						linePos++;
						if (line.find(s1, copyLinePos) == copyLinePos) {
							i = 0;
						}
					}
					i = 0;
					linePos = line.find(s1, linePos + 1);
				}
				newFile << copyLine << std::endl;
			}
		}
	}
	file.close();
	newFile.close();
	return newFileName;
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
		std::string		newFileName;

		if (errorRandling(argv[2], argv[3]))
			return -1;
		newFileName = openAndCopyFile(argv[1], argv[2], argv[3]);
		//replace(newFileName, argv[2], argv[3]);
	}
	return 0;
}
