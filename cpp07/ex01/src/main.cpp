/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 15:15:00 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>
#include <ctype.h>
#include <iomanip>

template<typename T>
T plusOne(T c) {
	return c + 1;
}

int main() {
	std::cout << CLEAR_SCREEN;

	std::cout << BOLD << BLUE << "---------------- Test with std::string array:\n" << RESET << std::endl;
	std::string array = "abcdef";
	size_t len = 4;
	std::cout << "Array before iter: " << array << std::endl;
	::iter<std::string&, int, int>(array, len, toupper);// Explicit instanciation
	std::cout << "Array after iter (touper): " << array << std::endl << std::endl;

	std::cout << BOLD << BLUE << "---------------- Test with int array and function template as third parameter:\n" << RESET << std::endl;
	int arrayInt[6] = {0,1,2,3,4,5};
	std::cout << "Array before iter: ";
	for (size_t i = 0; i < 6; i++) {
		std::cout << arrayInt[i];
	}
	std::cout << std::endl;
	::iter(arrayInt, 6, plusOne<int>);// Implicit instanciation
	std::cout << "Array after iter (plusOne): ";
	for (size_t i = 0; i < 6; i++) {
		std::cout << arrayInt[i];
	}
	std::cout << std::endl << std::endl;

	return 0;
}

/* std::string
 *   operator[] returns a reference
 *   c_str() and data() return a pointer.
 *
 * obs.: don't use pointers to std::string, unless you determine (by measuring)
 * that string copies are the bottleneck in your application.
 */
