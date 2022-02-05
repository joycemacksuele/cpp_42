/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/05 13:42:59 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen.hpp"

std::string	userInput( void ) {
	std::string	level;

	std::cout << std::endl << "Chose your level (or ctrl-c to exit): " << BLUE;
	std::getline(std::cin, level);
	return level;
}

int		main(void) {
	std::string	level;
	Karen		karen = Karen();

	std::cout << std::endl << GREEN << "Levels available: DEBUG, INFO, WARNING and ERROR!" << RESET << std::endl;
	level = userInput();
	while (std::strcmp(level.c_str(), "DEBUG") || std::strcmp(level.c_str(), "INFO") ||
				std::strcmp(level.c_str(), "WARNING") || std::strcmp(level.c_str(), "ERROR")) {
		if (!std::strcmp(level.c_str(), "DEBUG") || !std::strcmp(level.c_str(), "INFO") ||
				!std::strcmp(level.c_str(), "WARNING") || !std::strcmp(level.c_str(), "ERROR")) {
			karen.complain(level);
			level = userInput();
			continue ;
		}
		std::cout << YELLOW << "wrong level, try again!" << RESET << std::endl;
		level = userInput();
	}
	return 0;
}
