/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/18 18:18:36 by jfreitas      ########   odam.nl         */
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
	private:
		T* _element;
		unsigned int _elementSize;

	public:
        /* Constructing:
         * If you have not explicitly added any other constructor call for a member
         * variable into the initialization list, the default constructor of that
         * member will be invoked (for any member having a default constructor).
         */

		// Construction with no parameter: Creates an empty array.
		Array(void)
		: _element(new T[0]), _elementSize(0) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Default constructor called" << std::endl;
		}

		// Parametized construction: Creates an array of n elements initialized by default.
		Array(unsigned int n) 
        : _element(new T[n]), _elementSize(n) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Overloaded constructor called" << std::endl;
			// the one down below would not be initializatin by default
			/*
             for (unsigned int i = 0; i < n; i++) {
			 	_element[i] = 0;
             }
             */
		}

        /* OBS.:
         * - In C++, assignment and copy construction are different because the
         * copy constructor initializes uninitialized memory, whereas assignment
         * starts with an existing initialized object.
         * - In general, copy ctors should invoke the copy ctors of their members.
         *
         */

		// Copy constructor
		// Obs.: modifying the original array or its copy after copying musn’t affect the other array.
		Array(Array const &rhs)
        : _element(new T[rhs._elementSize]), _elementSize(rhs._elementSize) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Copy constructor called" << std::endl;
		}

		// Assignment operator
		// Obs.: modifying the original array or its copy after copying musn’t affect the other array.
		Array& operator=(Array const &rhs) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Assignment operator called" << std::endl;
			if (this != &rhs && this->_elementSize >= 0) {
			    delete [] this->_element;
				/* getting the size of the rhs element and if that size is >=
			    * 0, then a new array with that size can be allocated and
			    * assigned to each index of the rhs element.
                */
				this->_elementSize = rhs.size();
			    this->_element = new T[this->_elementSize];
			    for (unsigned int i = 0; i < this->_elementSize; i++) {
				    this->_element[i] = rhs._element[i];
                }
			}
			return *this;
		}

		// Subscript operator
		// Obs.: if its index is out of bounds, an std::exception is thrown.
		T& operator[](unsigned int index) {
			//std::cout << GREEN << "Array" << RESET;
			//std::cout << " Subscript operator called" << std::endl;
			if (index >= _elementSize || index < 0) {
				throw Array::InvalidIndexException();
			}
			return _element[index];
		}

		// Destructor
		~Array(void) {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " Destructor called" << std::endl;
			delete [] this->_element;
		}

		// Returns the number of elements in the array and musn’t modify the current instance.
		unsigned int size() const {
			std::cout << GREEN << "Array" << RESET;
			std::cout << " size() method called" << std::endl;

			/*
            T* elementCopy;
			for (elementCopy = _element; *elementCopy; elementCopy++);
			//std::cout << "elementCopy - _element = " << std::dec << (long)(elementCopy - _element) << std::endl;
			return elementCopy - _element;// computation with addresses
			*/

		    /*	
            unsigned int elementSize;
			for (elementSize = 0; this->_element[elementSize]; elementSize++);
			return elementSize;
			*/

			/* can't use those 2 ways above since the initiaization of the array
             * is by default (i.e.: has memory garbage), and the value on it can
             * happen to be 0 so the *elementCopy or this->_element[elementSize]
             * won't exist. 
             */

			return _elementSize;
		}

		class InvalidIndexException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Array::InvalidIndexException";
				}
		};
};

#endif
