/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 15:57:20 by jfreitas      ########   odam.nl         */
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


/* You MUST use the operator new[] to allocate memory.
 * Preventive allocation (allocating memory in advance) is forbidden.
 * Your program must never access nonallocated memory.
 */

template <class T>
class Array {
	public:

		// Construction with no parameter: Creates an empty array.
		Array(void) {
		}

		// Parametized construction: Creates an array of n elements initialized by default.
		Array(unsigned int n) {
			//Tip: Try to compile int * a = new int(); then display *a
		}

		// Copy constructor
		// Obs.: odifying the original array or its copy after copying musn’t affect the other array.
		Array(Array const &src) {
		}

		// Assignment operator
		// Obs.: odifying the original array or its copy after copying musn’t affect the other array.
		Array& operator=(Array const &rhs) {
		}

		// Subscript operator
		// Obs.: if its index is out of bounds, an std::exception is thrown.
		T& operator[](T *index) {
		}

		// Desctuctor
		~Array(void) {
		}

		// Returns the number of elements in the array and musn’t modify the current instance.
		unsigned int size() {
		}

	private:
		T element;
};

#endif
