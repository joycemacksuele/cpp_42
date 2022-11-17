/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 18:26:48 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

int main() {
	std::cout << CLEAR_SCREEN;

	std::cout << BOLD << BLUE << "---------------- Test with std::string array:\n" << RESET << std::endl;
	//Tip: Try to compile int * a = new int(); then display *a
	int *a = new int();
	std::cout << *a << std::endl;

	// It is compulsory to specify the type when declaring objects of class templates.
	// Otherwise, the compiler will produce an error.
	Array<int> array(8);// Explicit instanciation
	//std::cout << "Array after: " ;
	//for (size_t i = 0; i < 8; i++) {
	//	std::cout << array[i];
	//}
	
	delete a;
	std::cout << std::endl << std::endl;

	return 0;
}
