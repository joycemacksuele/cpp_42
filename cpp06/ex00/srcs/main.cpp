/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 12:27:48 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/05 17:09:27 by jfreitas      ########   odam.nl         */
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
		std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
		std::cout << "Min float: " << std::numeric_limits<float>::lowest() << std::endl;
		std::cout << "Mantissa (decimal part) float: " << std::numeric_limits<float>::max_digits10 - 2 << std::endl;// -2 that are used to convert from decimal to binary
		std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;
		std::cout << "Min double: " << std::numeric_limits<double>::lowest() << std::endl;
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
 * to overflow an int:
 * 2147483648
 * -2147483649
 *
 * to overflow a float:
 * 3402823466385288598117041834845169254400.00000000
 * -3402823466385288598117041834845169254400.00000000
 *
 * to overflow a double:
 * 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583610.000000000000000
 * -1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583610.000000000000000
 ******************************************************************************/
