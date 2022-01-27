/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/26 00:01:02 by jfreitas         ###   ########.fr       */
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
		while (newFile) {
			if (newFile.eof())
				break ;
			std::getline(newFile, line);
			size_t found = line.find(s1);
			std::cout << "--" << found << std::endl;
			if (found != std::string::npos) {
				i = 0;
				while (found < line.size() && (line[found] != '\n' || line[found] != '\0')) {
					std::cout << line[found] << "|" << s2[i] << std::endl;
					if (s2[i]) {
						line[found] = s2[i];
						std::cout << line  << std::endl;
						newFile << line;//something wrong here
					}
					i++;
					found++;
				}
			}
		}
	}
	newFile.close();
}

std::string	openAndCopyFile(std::string fileName) {
	std::fstream	file;
	std::fstream	newFile;
	std::string		newFileName;
	char			c;

	newFileName = fileName + ".replace";
	file.open(fileName, std::fstream::in);
	newFile.open(newFileName, std::fstream::out);
	if (file.is_open() && newFile.is_open()) {
		while (1) {
			c = file.get();
			if (file.eof())
				break ;
			newFile << c;
		}
	}
	file.close();

	//std::string		line;
	//std::getline(newFile, line);
	//std::cout << "--" << line << std::endl;

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
		newFileName = openAndCopyFile(argv[1]);
		replace(newFileName, argv[2], argv[3]);
	}
	return 0;
}
