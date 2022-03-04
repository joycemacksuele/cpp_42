/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/03/04 17:08:00 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed(void) : _number( 0 ) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_number = src.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const {// returns the raw value of the fixed-point value.
	std::cout << "getRawBits member function called" << std::endl;
	return this->_number;
}

void	Fixed::setRawBits( int const raw ) {// sets the raw value of the fixed-point number.
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}
