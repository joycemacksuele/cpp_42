/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/03/10 12:30:46 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed(void) 
	: _number(0) {
	// Using initialization list so the var is initialized right when the object is created.
	// Before the body of the constructor is executed (besides being assigned to a value inside of it).
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
//
// Shallow copy -  Only the pointer is copied (not what it's pointing to), so both
// objects points to the same memory (so if memery is allocated and freed, the
// copy object will be pointing to a freed memory space).
// Better to use when not dealing with raw pointers.
// EX:
//   Fixed::Fixed(const Fixed &src) : this(src) {} ?
//   Fixed::Fixed(const Fixed &src) : _number(src._number) {}
//
// Deep copy - What the pointer is pointing to is copied, so each copy will have
// its own address (each object will have a unique pointer).
// Better to use when dealing with raw pointers.
// EX:
//   Fixed::Fixed(const Fixed &src) {
//       this = new Fixed;
//       *this = src;
//   }
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called (shallow copy)" << std::endl;
	*this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &src) {
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

void	Fixed::setRawBits( const int raw ) {// sets the raw value of the fixed-point number.
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}
