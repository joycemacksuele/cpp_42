/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 19:48:55 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

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

	if (line.find(s1, linePos) == std::string::npos) { // npos = no position (s1 was not found in line)
		newFile << line;
		return ;
	}
	while ((linePos = line.find(s1, i)) != std::string::npos) {
		while (i < linePos) {
			newFile << line[i];
			i++;
		}
		for (size_t j = 0; j < s2.size(); j++) {
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

	file.open(fileName, std::fstream::in);// in for reading (could also be of type std::ifstream then file.open(fileName);)
	if (file.is_open()) {
		newFileName = fileName + ".replace";
		newFile.open(newFileName, std::fstream::out);// out for writing (could also be of type std::ostream then newFile.open(newFileName);)
		if (newFile.is_open()) {
			while (std::getline(file, line)) {
				copyReplace(newFile, line, s1, s2);
				newFile << std::endl;
			}
		}
	} else {
		std::cout << YELLOW << "File " << fileName << " does not exist... Try again!" << std::endl << RESET;
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
	} else {
    	std::cout << GREEN << "<original file name> <s1> <s2> " << YELLOW << "are needed as arguments!" << std::endl << RESET;
    }
	return 0;
}
