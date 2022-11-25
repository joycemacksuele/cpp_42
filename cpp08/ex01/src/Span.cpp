/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/25 15:17:20 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

bool Span::verbose = false;

Span::Span(void)// Default (no args) constructor
	: _spanSize(0), _intVector(0) {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Default constructor called" << std::endl;
	}
}

Span::Span(unsigned int const & N)// Overloaded constructor
	: _spanSize(N), _intVector(0) {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Overloaded constructor called" << std::endl;
	}
}

Span::Span(Span const & rhs)// Copy constructor
	: _spanSize(rhs._spanSize), _intVector(rhs._intVector) {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Copy constructor called" << std::endl;
	}
}

Span & Span::operator=(Span const & rhs) {// Assignment operator
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Assignment operator called" << std::endl;
	}
	if (this != &rhs) {
		this->_spanSize = rhs.getSpanSize();
		this->_intVector = std::vector<int>(rhs.getSpanSize());
		if (rhs._intVector.size() > 0) {
			this->_intVector = rhs._intVector;// vector class has = operator
		}
	}
	return *this;
}

Span::~Span(void) {// Destructor
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Destructor called" << std::endl;
	}
}

// Obs.: if its index is out of bounds, an std::exception is thrown.
int& Span::operator[](unsigned int index) {// Subscript operator
	/*if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " Subscript operator called" << std::endl;
	}*/
	if (index >= _spanSize || index < 0) {
		throw std::out_of_range("Span::Exception: Index put of range");
	}
	return _intVector[index];
}
/************************ getters and setters *************************/
unsigned int const & Span::getSpanSize() const {
	return _spanSize;
}

void Span::setSpanSize(unsigned int const & elements) {
	_spanSize = elements;
}

std::vector<int> const & Span::getVector() const {
	return _intVector;
}

void Span::setIntVector(std::vector<int> const & intVector) {
	_intVector = intVector;
}

/************************** member methods ****************************/
/* Adds a single number to the Span. It will be used in order to fill it.
 * Any attempt to add a new element if there are already N elements
 * stored should throw an exception.
 */
void Span::addNumber(int const & toAdd) {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " addNumber() called (to add " << toAdd << ")" << std::endl;
	}
	if (this->_intVector.size() == this->getSpanSize()) {
		 throw std::range_error("Span is full!");
	}
	this->_intVector.push_back(toAdd);
}

/* finds out the shortest span (or distance, if you prefer) between all
 * the numbers stored, and return it. If there are no numbers stored,
 * or only one, no span can be found. Thus, throw an exception.
 */
int Span::shortestSpan() const {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " shortestSpan() called" << std::endl;
	}
	if (this->_intVector.size() <= 1) {
		 throw std::range_error("Not enought elements for a span to be found!");
	}
	std::vector<int> sortedVec = this->_intVector;
	std::sort(sortedVec.begin(), sortedVec.end());
	
	/*
	for (int i = 0; i < 5; i++) {
		std::cout << "sorted span[" << i << "] = " << sortedVec[i] << std::endl;
	}
	*/

	/* std::adjacent_difference:
	 * Computes the differences between the second and the first of each
	 * adjacent pair of elements of the range [first, last) and writes them to
	 * the range beginning at d_first + 1. An unmodified copy of *first is
	 * written to *d_first.
	 */
	std::adjacent_difference(sortedVec.begin(), sortedVec.end(), sortedVec.begin());

	/*
	for (int i = 1; i < 5; i++) {
		std::cout << "adjacent_difference span[" << i << "] = " << sortedVec[i] << std::endl;
	}
	*/

	return *std::min_element(std::next(sortedVec.begin()), sortedVec.end());
}

/* finds out the longest span (or distance, if you prefer) between all
 * the numbers stored, and return it. If there are no numbers stored,
 * or only one, no span can be found. Thus, throw an exception.
 */
int Span::longestSpan() const {
	if (verbose) {
		std::cout << GREEN << "Span" << RESET;
		std::cout << " longestSpan() called" << std::endl;
	}
	if (this->_intVector.size() <= 1) {
		 throw std::range_error("Not enought elements for a span to be found!");
	}
	std::vector<int> sortedVec = this->_intVector;
	std::sort(sortedVec.begin(), sortedVec.end());

	/*
	for (int i = 0; i < 5; i++) {
		std::cout << "sorted span[" << i << "] = " << sortedVec[i] << std::endl;
	}
	std::cout << "sortedVec.front(): " << sortedVec.front() << " | sortedVec.back(): " << sortedVec.back() << std::endl;
	*/

	return (sortedVec.back() - sortedVec.front());
}

void Span::addNumbers(int const & value) {
	this->_intVector = std::vector<int>(this->getSpanSize());
	std::fill(_intVector.begin(), _intVector.end(), value);
}

void Span::addIntVectorToSpan(std::vector<int> const & intVecToAdd) {
	this->_spanSize = this->_spanSize + intVecToAdd.size();
	this->_intVector.insert(_intVector.end(), intVecToAdd.begin(), intVecToAdd.end());
}
