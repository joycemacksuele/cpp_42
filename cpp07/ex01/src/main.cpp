/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/21 15:30:59 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

template<typename T>
T plusOne(T& c) {
	c = c + 1;
	return c;
}
void ft_toupper(char& c) {
	c = c - 32;
}

template<typename T>
void print(T const &atIndex) {
	std::cout << atIndex << " ";
}

int main() {
	std::cout << CLEAR_SCREEN;

	std::cout << BOLD << BLUE << "---------------- Test with std::string array:\n" << RESET << std::endl;
	std::string array = "abcdef";
	unsigned int len = 4;
	std::cout << "Array before iter: " << array << std::endl;
	::iter<std::string, void, char>(array, len, ft_toupper);// Explicit instanciation
	std::cout << "Array after iter (touper): ";
	::iter(array, 6, print<char>);
	std::cout << std::endl << std::endl;

	std::cout << BOLD << BLUE << "---------------- Test with int array and function template as third parameter:\n" << RESET << std::endl;
	int arrayInt[6] = {0,1,2,3,4,5};
	std::cout << "Array before iter: ";
	for (size_t i = 0; i < 6; i++) {
		std::cout << arrayInt[i];
	}
	std::cout << std::endl;
	::iter(arrayInt, 6, plusOne<int>);// Implicit instanciation
	std::cout << "Array after iter (plusOne): ";
	::iter(arrayInt, 6, print<int>);
	std::cout << std::endl << std::endl;

	return 0;
}

/* std::string
 *   operator[] returns a reference (can be changed)
 *   c_str() and data() return a const pointer by value (can't be changed)
 *
 * obs.: don't use pointers to std::string, unless you determine (by measuring)
 * that string copies are the bottleneck in your application.
 */
