/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/04/23 11:10:22 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed(void)// {
	: _fixedNumber(0), _fractionalBit(8) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Constructor that converts it's param to the corresponding fixed-point value.
// The fractional bits value is initialized to 8.
Fixed::Fixed(const int number)// {
	: _fixedNumber(number), _fractionalBit(8) {
	std::cout << "Int constructor called" << std::endl;
	_fixedNumber = number << _fractionalBit;
	return ;
}

/* Constructor that converts its param to the corresponding fixed-point value.
 * The fractional bits value is initialized to 8.
 *
 * A floating-point constant without an f, F, l, or L suffix has type double.
 * If the letter f or F is the suffix, the constant has type float.
 * If suffixed by the letter l or L, it has type long double.
 */
Fixed::Fixed(const float numberFloat)// {
	: _fractionalBit(8) {

/* -> Converting from a floating-point value to a fixed-point value involves
 * the following steps:
 * Multiply the float by 2^(number of fractional bits for the type),
 * cast to an integer type, leaving an integer value and assign this value
 * into the fixed-point type.
 * e.g. for 24.4: fixed_point = (int)(float * 2^4) 
 */
	_fixedNumber = (int)(numberFloat * (2 ^ _fractionalBit));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
	: _fractionalBit(8) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
// Initializes an existing object to the value supplied by another existing object.
Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		//this->_fixedNumber = rhs.getRawBits(); or ->
		this->setRawBits(rhs.getRawBits());
	}
	return *this;
}

// An overload of the insertion («) operator that inserts a floating-point
// representation of the fixed-point number into the output stream object passed as parameter
std::ostream& operator<<(std::ostream &output, const Fixed &rhs) {
	output << rhs.toFloat();
	return output;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
	//fixed-point value = _fixedNumber
	//number of fractional bits = _fractionalBit
	int sign = 1;
	if (_fixedNumber < 0) {
		sign = -1;
	}
	//this->setRawBits(_number ...)
	return 0;

}

// Converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
	return _fixedNumber;
}


int Fixed::getRawBits(void) const {// returns the raw value of the fixed-point value.
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNumber;
}

void Fixed::setRawBits(const int raw) {// sets the raw value of the fixed-point number.
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNumber = raw;
}

/* the decimal point is called binary point or radix in binary notation, but it
 * is nor explicitly stored, so it's kept in a fixed position (which we have to know).
 */
