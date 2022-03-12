/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/03/12 13:47:03 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed(void)// {
	: _number(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Constructor that initializes the fixed-point number value to the corresponding param.
Fixed::Fixed(const int number)// {
	: _number(number) {
	std::cout << "Int constructor called" << std::endl;
	return ;
}

// Constructor that initializes the fixed-point number value to the corresponding param.
// A floating-point constant without an f, F, l, or L suffix has type double.
// If the letter f or F is the suffix, the constant has type float.
// If suffixed by the letter l or L, it has type long double.
Fixed::Fixed(const float number)// {
	: _number(number) {
	std::cout << "Float constructor called" << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &src) {
	//: _number(src._number) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
// Initializes an existing object to the value supplied by another existing object.
Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_number = rhs.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &stream, const Fixed &rhs) {
	stream << rhs.toFloat(rhs.getRawBits());
	return stream;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

float Fixed::toFloat(void) {
	this->setRawBits(_number ...)
}

int Fixed::toInt(void) {

}


int Fixed::getRawBits(void) const {// returns the raw value of the fixed-point value.
	std::cout << "getRawBits member function called" << std::endl;
	return this->_number;
}

void Fixed::setRawBits(const int raw) {// sets the raw value of the fixed-point number.
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}
