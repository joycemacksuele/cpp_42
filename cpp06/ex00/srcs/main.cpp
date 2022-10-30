/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 12:27:48 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/30 14:52:10 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

//#include <typeinfo>
// typeid: typeid (expression)
// typeid allows to check the type of an expression

int main(int argc, char **argv) {
	if (argc == 2 || (argc == 3 && std::strcmp(argv[1], "-v") == 0)) {
		ExplicitConversion explicitConversion = ExplicitConversion();
		if (std::strcmp(argv[1], "-v") == 0) {
			explicitConversion = ExplicitConversion(argv[2], true);
		} else {
			explicitConversion = ExplicitConversion(argv[1], false);
		}
		explicitConversion.assignLiteral();
		std::cout << explicitConversion;// outputs the convertions
	} else {
		std::cout << "Usage: ./convert [-v] <literal>" << std::endl;
		std::cout << "literal: <char> | <int> | <float> | <double>" << std::endl;
	}
	return 0;
}
