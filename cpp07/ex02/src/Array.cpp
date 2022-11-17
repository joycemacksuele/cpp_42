/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 15:51:50 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

/* You MUST use the operator new[] to allocate memory.
 * Preventive allocation (allocating memory in advance) is forbidden.
 * Your program must never access nonallocated memory.
 */

// Construction with no parameter: Creates an empty array.
Array::Array(void) {
}

// Parametized construction: Creates an array of n elements initialized by default.
array::Array(unsigned int n) {
	//Tip: Try to compile int * a = new int(); then display *a
}

// Copy constructor
// Obs.: odifying the original array or its copy after copying musn’t affect the other array.
Array::Array(Array const &src) {
}

// Assignment operator
// Obs.: odifying the original array or its copy after copying musn’t affect the other array.
Array& Array::operator=(Array const &rhs) {
}

// Subscript operator
// Obs.: if its index is out of bounds, an std::exception is thrown.
T& Array::operator[](T *index) {
}

// Desctuctor
~Array:Array(void) {
}

// Returns the number of elements in the array and musn’t modify the current instance.
unsigned int Array::size() {
}
