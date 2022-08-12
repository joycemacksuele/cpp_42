/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/12 17:23:46 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

static void print_arg_option() {
	std::cout << "-------------------------" << std::endl;
	std::cout << "Options of arguments: " << std::endl;
	std::cout << GREEN << "<grade number>" << std::endl;
	std::cout << "<grade number> <increment>" << std::endl;
	std::cout << "<grade number> <decrement>";
	std::cout << RESET << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int main(int argc, char **argv) {
	if (argc == 2 && std::isdigit(argv[1][0])) {
		const unsigned int& grade = std::atoi(&argv[1][0]);
		try {
			Bureaucrat bureaucrat = Bureaucrat("Joyce", grade);
			std::cout << bureaucrat;
		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error: " RESET BOLD << e.what() << std::endl;
		}

	/*************************************************************************/

	} else if (argc == 3 && std::strcmp(&argv[2][0], "increment") == 0) {
		const unsigned int& grade = std::atoi(&argv[1][0]);
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bu", grade);
			std::cout << bureaucrat;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat;
		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error: " RESET BOLD << e.what() << std::endl;
		}

	/*************************************************************************/

	} else if (argc == 3 && std::strcmp(&argv[2][0], "decrement") == 0) {
		const unsigned int& grade = std::atoi(&argv[1][0]);
		try {
			Bureaucrat bureaucrat = Bureaucrat("De", grade);
			std::cout << bureaucrat;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat;
		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error: " RESET BOLD << e.what() << std::endl;
		}

	/*************************************************************************/

	} else {
		print_arg_option();
	}
	return 0;
}
