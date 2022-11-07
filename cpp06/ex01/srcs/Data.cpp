/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 16:05:08 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

/* ######################### OrthodoxCanonical Form ######################### */

// Private Default constructor
Data::Data(void)
	: _verbose(false) {
	if (isVerbose()) {
		std::cout << GREEN << "Data" << RESET;
		std::cout << " Default constructor called" << std::endl;
	}
	return ;
}

// Overloaded constructor
Data::Data(bool const verbose)
	: _verbose(verbose) {
	if (isVerbose()) {
		std::cout << GREEN << std::endl << "Data" << RESET;
		std::cout << " Overloaded constructor called" << std::endl;
	}
	return ;
}

// Copy constructor
Data::Data(Data const &src) {
	if (isVerbose()) {
		std::cout << GREEN << "Data" << RESET;
		std::cout << " Copy constructor called" << std::endl;
	}
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Data& Data::operator=(Data const &rhs) {
	if (isVerbose()) {
		std::cout << GREEN << "Data" << RESET ;
		std::cout << " Copy assignment operator called" << std::endl;
	}
	if (this != &rhs) {
		this->_verbose = rhs._verbose;
	}
	return *this;
}

// Destructor
Data::~Data(void) {
	if (isVerbose()) {
		std::cout << RED << "Data" << RESET;
		std::cout << " Destructor called" << std::endl << std::endl;
	}
	return ;
}

/* ########################## Class member methods ########################## */

bool Data::isVerbose() const {
	return _verbose;
}
