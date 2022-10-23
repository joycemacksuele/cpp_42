/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 12:27:48 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/22 17:24:26 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>
#include <typeinfo>

#include <iostream>
#include <iomanip>

// typeid: typeid (expression)
// typeid allows to check the type of an expression

bool inputIsChar(const std::string& argv) {
	if (argv.size() == 1 && ((argv.at(0) >= 0 && argv.at(0) <= 47)
				|| (argv.at(0) >= 58 && argv.at(0) <= 127))) {
		return true;
	}
	return false;
}

bool inputIsInt(const std::string& argv) {
	try {
		if (argv.back() != 'f' && std::strcmp(argv.c_str(), "nan") != 0
			&& argv.find('.') == std::string::npos) {
			std::stoi(argv);
			return true;
		}
	} catch (...) {
		std::cout << "not INT - exception- CONTINUE" << std::endl;
		return false;
	}
	return false;
}

bool inputIsFloat(const std::string& argv) {
	try {
		if (argv.back() == 'f' && (std::strcmp(argv.c_str(), "inf") != 0
			&& std::strcmp(argv.c_str(), "nan") != 0)) {
			std::stof(argv);
			return true;
		}
	} catch (...) {
		std::cout << "UNKNOWN FLOAT" << std::endl;
		return false;
	}
	return false;
}

bool inputIsDouble(const std::string& argv) {
	try {
		std::stod(argv);
		return true;
	} catch (...) {
		std::cout << "UNKNOWN DOUBLE" << std::endl;
		return false;
	}
	return false;
}

bool inputIsPseudo(const std::string& argv) {
	for (unsigned long i = 0; i < argv.size(); i++) {
		if (std::strcmp(argv.c_str(), "inff") == 0
				|| std::strcmp(argv.c_str(), "nanf") == 0
				|| std::strcmp(argv.c_str(), "inf") == 0
				|| std::strcmp(argv.c_str(), "nan") == 0) {
			break ;// it is float or double
		}
		if (argv[i] && std::isdigit(argv[i])) {
			continue ;
		}
		if (i == argv.size() -1 && argv.back() != 'f') {
			break ;// it is a float
		}
		if (i != argv.size() - 1 && argv[i] != '.') {
			std::cout << "UNKNOWN INT" << std::endl;
			return false;
		}
	}
	return true;
}

ConvertTo checkInput(std::string argv) {
	if (inputIsChar(argv)) {
		return ::CHAR;
	}

	if (argv.front() == '-' || argv.front() == '+') {
		argv.erase(0, 1);
	}

	if (inputIsPseudo(argv) == false) {
		return ::UNKNOWN;
	}
	if (inputIsInt(argv)) {
		return ::INT;
	}
	if (inputIsFloat(argv)) {
		return ::FLOAT;
	}
	if (inputIsDouble(argv)) {
		return ::DOUBLE;
	}
	return ::UNKNOWN;
}


int main(int argc, char **argv) {
	std::cout << std::endl;
	if (argc == 2 || (argc == 3 && std::strcmp(argv[1], "-v") == 0)) {
		//ConvertTo type;
		/*if ((type = checkInput(argv[1])) == ::UNKNOWN) {
			std::cout << "Invalid argument. Try again!" << std::endl;
		} else {*/

		ExplicitConversion explicitConversion = ExplicitConversion();
		if (std::strcmp(argv[1], "-v") == 0) {
			explicitConversion = ExplicitConversion(argv[2], true);
		} else {
			explicitConversion = ExplicitConversion(argv[1], false);
		}
		explicitConversion.assignLiteral();
		std::cout << explicitConversion;
		//}
	} else {
		std::cout << "Arguments accepted: <char>, <int>, <float> or <double>" << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
