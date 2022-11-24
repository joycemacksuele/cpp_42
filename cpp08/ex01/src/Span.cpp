/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/24 17:30:24 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

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
	if (Span::verbose) {
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
	if (this->_intVector.size() == this->getSpanSize()) {
		 throw std::range_error("Span is full!");
	}
	this->_intVector.emplace_back(toAdd);
}

/* finds out the shortest span (or distance, if you prefer) between all
 * the numbers stored, and return it. If there are no numbers stored,
 * or only one, no span can be found. Thus, throw an exception.
 */
int Span::shortestSpan() const {
	if (this->_intVector.size() <= 1) {
		 throw std::range_error("Not enought elements for a span to be found!");
	}
	std::vector<int> tmp = this->_intVector;
	std::sort(tmp.begin(), tmp.end());
	return std::distance(tmp.begin(), tmp.begin() + 1);
}

/* finds out the longest span (or distance, if you prefer) between all
 * the numbers stored, and return it. If there are no numbers stored,
 * or only one, no span can be found. Thus, throw an exception.
 */ 
int Span::longestSpan() const {
	if (this->_intVector.size() <= 1) {
		 throw std::range_error("Not enought elements for a span to be found!");
	}
	std::vector<int> tmp = this->_intVector;
	std::sort(tmp.begin(), tmp.end());
	return std::distance(tmp.begin(), tmp.end());
}
