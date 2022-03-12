/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/03/12 12:46:59 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed(void) {
	//: _number(0) {
	// Using initialization list so the var is initialized right when the object
	// is created before the body of the constructor is executed (besides being
	// assigned to a value inside of it).
	std::cout << "Default constructor called" << std::endl;
	_number = 0;
	return ;
}

// Copy constructor
// The purpose of a copy constructor is to create new objects from existing objects.
// When objects are copied, cpp must create a new object from an existing object.
// - Objects can be copied by being passed as a paremeter or being returned from a,
// funtion (by value) or by being constructed based on another object of the same class.
//
// Shallow copy -  Only the pointer is copied (not what it's pointing to), so both
// objects points to the same memory (so if memory is allocated and freed, the
// copy object will be pointing to a freed memory space).
// Better to use when not dealing with raw pointers.
// - Cpp provides a compiler-defined (shallow) copy constructor if you don't.
// EX:
//   Fixed::Fixed(const Fixed &src) : this(src) {} ?
//   Fixed::Fixed(const Fixed &src) : _number(src._number) {}
// 
//
// Deep copy - What the pointer is pointing to is copied, so each copy will have
// its own address (each object will have a unique pointer).
// Better to use when dealing with raw pointers.
// EX:
//   Fixed::Fixed(const Fixed &src) {
//       this = new Fixed;
//       *this = src; // this will call the copy assignment operator
//   }
//
// Conclusion: It is most useful to have a copy constructor if your class has raw
// pointer, since the compiler-generated copy constructor won't copy the value/data
// that the pointer is point to, it will copy only the pointer.
Fixed::Fixed(const Fixed &src) {
	//: _number(src._number) {
	std::cout << "Copy constructor called" << std::endl;
	//_number = src.getRawBits();
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
// Initializes an existing object to the value supplied by another existing object.
Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {// comparing the pointer to the object themselve so self assignment won't happen
		this->_number = rhs.getRawBits();
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
