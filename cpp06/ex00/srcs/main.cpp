/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 12:27:48 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/02 14:21:46 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>
#include <typeinfo>


// typeid: typeid (expression)
// typeid allows to check the type of an expression
//
ConvertTo checkInput(std::string argv) {
	std::cout << "JOY: " << argv << std::endl;
	/* check char */
	if (argv.size() == 1 && ((argv.at(0) >= 0 && argv.at(0) <= 47)
				|| (argv.at(0) >= 58 && argv.at(0) <= 127))) {
		std::cout << "CHAAR" << std::endl;
		return ::CHAR;
	}

	if (argv.front() == '-' || argv.front() == '+') {
		argv.erase(0, 1);
	}

	std::cout << "JOY: " << argv << std::endl;
	for (unsigned long i = 0; i < argv.size(); i++) {
		if (argv[i] && std::isdigit(argv[i])) {
			continue ;
		}
		if (argv.back() != 'f' || (argv.find('.') == std::string::npos
				&& std::strcmp(argv.c_str(), "nan") != 0
				&& std::strcmp(argv.c_str(), "inf") != 0)) {// TODO WRONG HERE WHEN i TRY 2147483648f
			std::cout << "UNKNOWN INT" << std::endl;
			return ::UNKNOWN;
		}
	}

	/* check int */
	try {
		if (argv.back() != 'f' && std::strcmp(argv.c_str(), "nan") != 0
			&& argv.find('.') == std::string::npos) {
			std::stoi(argv);
			std::cout << "INT" << std::endl;
			return ::INT;
		}
	} catch (...) {
		std::cout << "not INT - exception- CONTINUE" << std::endl;
	}
	
	/* check float */
	try {
		if (argv.back() == 'f' && (std::strcmp(argv.c_str(), "inf") != 0
			&& std::strcmp(argv.c_str(), "nan") != 0)) {
			std::stof(argv);
			std::cout << "FLOAT" << std::endl;
			return ::FLOAT;
		}
	} catch (...) {
		std::cout << "UNKNOWN FLOAT" << std::endl;
		return ::UNKNOWN;
	}

	/* check double */
	try {
		std::stod(argv);
		std::cout << "DOUBLE" << std::endl;
		return ::DOUBLE;
	} catch (...) {
		std::cout << "UNKNOWN DOUBLE" << std::endl;
		return ::UNKNOWN;
	}
	std::cout << "UNKNOWN" << std::endl;
	return ::UNKNOWN;
}


int main(int argc, char **argv) {
	if (argc == 2) {
		if (checkInput(argv[1]) == ::UNKNOWN) {
			std::cout << std::endl << "Invalid argument. Try again!" << std::endl << std::endl;
		}
		//std::cout << "char: " << charConvertion(argv[1]) << std::endl;
		//std::cout << "int: " << intConversion(argv[1]) << std::endl;
		//std::cout << "float: " << floatConversion(argv[1]) << std::endl;
		//std::cout << "double: " << doubleConversion(argv[1]) << std::endl;
	}
	return 0;
}
