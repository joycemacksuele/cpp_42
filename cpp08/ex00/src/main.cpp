/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/24 10:50:17 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
//Sequence containers:
#include <array>// static contiguous array
#include <vector>// dynamic contiguous array
#include <deque>// double-ended queue
#include <forward_list>// singly-linked list
#include <list>// doubly-linked list

template <typename T>
static std::string const containerToStr(T & element) {
	std::stringstream str;
	for (typename T::iterator it = element.begin(); it != element.end(); it++) {
		str << "["<< *it << "]";
	}
	return str.str();
}

int main() {
	std::cout << CLEAR_SCREEN << std::endl;

	/**************************** My tests ************************************/
	try {
		std::array<int, 3> intArray = {1, 1, 1};
		std::cout << "Container: " << containerToStr(intArray) << std::endl;
		std::cout << "Int to find: " << 1 << std::endl;
		std::array<int, 3>::iterator arrayIt = ::easyfind(intArray, 1);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *arrayIt << " exists on the array container)" << std::endl;
		std::cout << std::endl;

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

		std::deque<int> intDeque;
		intDeque.push_back(7);
		intDeque.push_back(77);
		intDeque.push_back(777);
		intDeque.push_back(42);
		intDeque.push_back(8);
		std::cout << "Container: " << containerToStr(intDeque) << std::endl;
		std::cout << "Int to find: " << 8 << std::endl;
		std::deque<int>::iterator dequeIt = ::easyfind(intDeque, 8);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *dequeIt << " exists on the deque container)" << std::endl;
		std::cout << std::endl;

		// std::forward_list doesn't store an iterator to the last element as
		// it is an implementaion of the singly linked list and to get to the
		// last element we wpuld have to go through all elements of it.
		std::forward_list<int> intFowardList;
		intFowardList.push_front(2147483647);
		intFowardList.push_front(99999999);
		intFowardList.push_front(23);
		intFowardList.push_front(42);
		intFowardList.push_front(-1);
		intFowardList.push_front(5555);
		intFowardList.push_front(555);
		intFowardList.push_front(55);
		intFowardList.push_front(0);
		std::cout << "Container: " << containerToStr(intFowardList) << std::endl;
		std::cout << "Int to find: " << 555 << std::endl;
		std::forward_list<int>::iterator fowardListIt = ::easyfind(intFowardList, 2147483647);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *fowardListIt << " exists on the foward_list container)" << std::endl;
		std::cout << std::endl;

		std::list<int> intList;
		intList.push_back(10);
		intList.push_back(100);
		intList.push_back(4242);
		std::cout << "Container: " << containerToStr(intList) << std::endl;
		std::cout << "Int to find: " << 2 << std::endl;
		std::list<int>::iterator listIt = ::easyfind(intList, 2);
		std::cout << BOLD << GREEN << "Result: OK " << RESET;
		std::cout << "(" << *listIt << " exists on the list container)" << std::endl;
	} catch(std::exception const& ex) {
		std::cerr << BOLD << RED << "Error: " << RESET << "2 " << ex.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
