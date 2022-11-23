/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/23 17:08:23 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <vector>
#include <list>

template <typename T>
static std::string const containerToStr(T & element) {
	std::stringstream str;
	for (typename T::iterator it = element.begin(); it != element.end(); it++) {
		str << "["<< *it << "]";
	}
	return str.str();//str() transforms std::stringstream to std::string
}

int main() {

	std::cout << CLEAR_SCREEN << std::endl;;
	/****************************** Codam tests *******************************/

	/**************************** My tests ************************************/
	try {
		// std::vector<int> intList = {1, 2, 3, 4, 5};// Error: cannot be initialized with an initializer list
		std::vector<int> intVec;
		intVec.push_back(0);
		intVec.push_back(1);
		intVec.push_back(2);
		std::cout << "Container: " << containerToStr(intVec) << std::endl;
		std::cout << "Int to find: " << 2 << std::endl;
		std::vector<int>::iterator vecIt = ::easyfind(intVec, 2);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *vecIt << " exists on the vector container)" << std::endl;
		std::cout << std::endl;


		std::list<int> intList;
		intList.push_back(10);
		intList.push_back(100);
		intList.push_back(4242);
		std::cout << "Container: " << containerToStr(intList) << std::endl;
		std::cout << "Int to find: " << 2 << std::endl;
		std::list<int>::iterator listIt = ::easyfind(intList, 2);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *listIt << " exists on the vector container)" << std::endl;
	} catch(std::exception const& ex) {
		std::cerr << BOLD << RED << "Error: " << RESET << "2 " << ex.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
