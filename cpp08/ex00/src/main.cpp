/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/23 16:02:52 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <vector>
#include <list>

int main() {

	std::cout << CLEAR_SCREEN;
	/**************************************************************************/
	//Codam tests

	/**************************************************************************/
	// My tests
	std::cout << BOLD << GREEN << std::endl;

	// std::list<int> intList = {1, 2, 3, 4, 5};// Error: cannot be initialized with an initializer list
	std::vector<int> intVec;
	intVec.push_back(0);
	intVec.push_back(1);
	//intVec.push_back(2);
	//std::list<int> intList = {1, 2, 3, 4, 5};

	try {
		std::vector<int>::iterator it = ::easyfind(intVec, 2);
		std::cout << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *it << " exists on the container)" << std::endl;
	} catch(std::exception const& ex) {
		std::cerr << RED << "Error: " << RESET << "2 " << ex.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
