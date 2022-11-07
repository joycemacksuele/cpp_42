/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 12:27:48 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 12:56:02 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

//#include <typeinfo>
// typeid: typeid (expression)
// typeid allows to check the type of an expression
// https://en.cppreference.com/w/cpp/types/numeric_limits

int main(int argc, char **argv) {
	/**************************************************************************/
	if (argc == 2 && std::strcmp(argv[1], "-l") == 0) {
		std::cout << std::endl;
		std::cout << "Max int: " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "Min int: " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "Inf int: " << std::numeric_limits<int>::infinity() << std::endl;
		std::cout << std::endl;
		std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
		std::cout << "Min float: " << std::numeric_limits<float>::lowest() << std::endl;
		std::cout << "Inf float: " << std::numeric_limits<float>::infinity() << std::endl;
		std::cout << "Mantissa (decimal part) float: " << std::numeric_limits<float>::max_digits10 - 2 << std::endl;// -2 that are used to convert from decimal to binary
		std::cout << std::endl;
		std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;
		std::cout << "Min double: " << std::numeric_limits<double>::lowest() << std::endl;
		std::cout << "Inf double: " << std::numeric_limits<double>::infinity() << std::endl;
		std::cout << "Mantissa (decimal part) double: " << std::numeric_limits<double>::max_digits10 - 3 << std::endl;// -2 that are used to convert from decimal to binary
		std::cout << std::endl;
		return 0;
	}
	/**************************************************************************/

	if (argc == 2 || (argc == 3 && std::strcmp(argv[1], "-v") == 0)) {
		ExplicitConversion explicitConversion = ExplicitConversion();
		if (argc == 3 && std::strcmp(argv[1], "-v") == 0) {
			explicitConversion = ExplicitConversion(argv[2], true);
		} else {
			explicitConversion = ExplicitConversion(argv[1], false);
		}
		explicitConversion.assignLiteral();
		std::cout << explicitConversion;// outputs the convertions
	} else {
		std::cout << "\nUsage: \v./convert [-v | -l] <literal>" << std::endl;
		std::cout << "\n[-v]: verbose\n[-l]: limits" << std::endl;
		std::cout << "<literal>: <char> | <int> | <float> | <double>\n" << std::endl;
	}
	return 0;
}

/*******************************************************************************
 * https://www.wolframalpha.com/input?i=10%5E308
 *
 * to overflow an int:
 * 2147483648
 * -2147483649
 *
 * to overflow a float:
 * 3402820000000000000000000000000000000000
 * -3402820000000000000000000000000000000000
 *
 * to overflow a double:
 * 1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
 * -1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
 ******************************************************************************/
