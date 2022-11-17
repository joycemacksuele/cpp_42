/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 16:02:57 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

int main() {
	std::cout << CLEAR_SCREEN;

	std::cout << BOLD << BLUE << "---------------- Test with std::string array:\n" << RESET << std::endl;
	int * a = new int();
	std::cout << "Array before: " << *a << std::endl;
	// It is compulsory to specify the type when declaring objects of class templates. Otherwise, the compiler will produce an error.
	a = Array<int>(8);// Explicit instanciation
	std::cout << "Array after: " ;
	for (size_t i = 0; i < 8; i++) {
		std::cout << a[i];
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
