/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 15:41:53 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/04/08 16:16:56 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"


int		main(void) {
	std::string	level;
	Harl		harl = Harl();

	std::cout << std::endl << "Levels available: DEBUG, INFO, WARNING and ERROR!" << std::endl;
	std::cout << "Chose your level (or ctrl-c to exit) " << BLUE << std::endl << std::endl;
	while (std::getline(std::cin, level)) {
		if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR") {
			harl.complain(level);
		} else {
			std::cout << YELLOW << "wrong level, try again!" << BLUE << std::endl << std::endl;
		}
	}
	return 0;
}
