/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 21:58:31 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define YELLOW        "\033[33m"
#define BLUE          "\033[34m"
#define MAGENTA       "\033[35m"
#define CYAN          "\033[36m"
#define BOLD          "\x1B[1m"
#define CLEAR_SCREEN  "\033c"
#define ERASE_LINE    "\033[2K"
#define JUMP_ONE_LINE "\033[1B"

#include <iomanip>

/* You MUST use the operator new[] to allocate memory.
 * Preventive allocation (allocating memory in advance) is forbidden.
 * Your program must never access nonallocated memory.
 */

template <class T>
class Array {
	public:

		// Construction with no parameter: Creates an empty array.
		Array(void) {
			_element = new T;
			_elementSize = 0;
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Default constructor called" << std::endl;
		}

		// Parametized construction: Creates an array of n elements initialized by default.
		Array(unsigned int n) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Overloaded constructor called" << std::endl;
			_elementSize = n;
			_element = new T[n];
			for (unsigned int i = 0; i <= n; i++) {
				_element[i] = 0;
			}
		}

		// Copy constructor
		// Obs.: modifying the original array or its copy after copying musn’t affect the other array.
		Array(Array const &src) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Copy constructor called" << std::endl;
			*this = src; // this will call the copy assignment operator
		}

		// Assignment operator
		// Obs.: modifying the original array or its copy after copying musn’t affect the other array.
		Array& operator=(Array const &rhs) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Copy assignment operator called" << std::endl;
			if (this != &rhs) {
				this->_elementSize = rhs._elementSize;
				/* getting the size of the rhs element and if that size is >=
				* 0, then a new array with that size can be allocated and
				* assigned to each index of the rhs element. */
				unsigned int size = rhs.size();
				if (size >= 0) {
					this->_element = new T[size];
					for (unsigned int i = 0; i <= size; i++)
						this->_element[i] = rhs._element[i];
				}
				//this->_element = rhs._element;
			}
			return *this;
		}

		// Subscript operator
		// Obs.: if its index is out of bounds, an std::exception is thrown.
		T& operator[](unsigned int index) {
			//std::cout << GREEN << "Array" << RESET;
			//std::cout << " Subscript operator called" << std::endl;
			// Using _elementSize rather than  size() here since for the just
			// constructed empty array, the size() metohod would return 0:
			//std::cout << "size() = "<< this->size() << std::endl;
			if (index > _elementSize || index < 0) {
				throw Array::InvalidIndexException();
			}
			return _element[index];
		}

		// Destructor
		~Array(void) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Destructor called" << std::endl;
			delete _element;
		}

		// Returns the number of elements in the array and musn’t modify the current instance.
		unsigned int size() const {
			//std::cout << GREEN << "Array" << RESET;
			//std::cout << " size() method called" << std::endl << std::endl;
			T* elementCopy;
			for (elementCopy = _element; *elementCopy; elementCopy++);
			//std::cout << "elementCopy = " << std::dec << (long)elementCopy << std::endl;
			//std::cout << "_element = " << std::dec << (long)_element << std::endl;
			//std::cout << "elementCopy - _element = " << std::dec << (long)(elementCopy - _element) << std::endl;
			return elementCopy - _element;// computation with addresses
			//unsigned int elementSize;
			//for (elementSize = 0; _element[elementSize]; elementSize++);
			//return elementSize;
		}

		class InvalidIndexException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Array::InvalidIndexException";
				}
		};

	private:
		T* _element;
		unsigned int _elementSize;
};

#endif
