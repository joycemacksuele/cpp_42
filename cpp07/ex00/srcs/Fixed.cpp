/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 16:36:11 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/09 15:48:26 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* Good to know: The decimal point is called binary point or radix in binary notation, but
 * it's not explicitly stored, so it's kept in a fixed position (which we have to know).
 */

/* ########################################################################## */

// Default constructor that initializes the fixed-point value value to 0.
Fixed::Fixed(void)// {
	: _frac_bit(8), _fixed_point_value(0)  {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
	: _frac_bit(8) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

/* The conversion from the int ot float number to the fixed point value is done by
 * shifting _frac_bit times to the left (<<) the fixed point value (binary).
 *
 * from int: just shifting is enough.
 * from float: a workaround has to be done to get an int number (aka: without the decimals).
 *
 * << means to do a multiplication by the fractional bits (in this case as the _frac_bits
 * is always 8, so the multiplication will be by 2^8 = 256 (1+2+4+8+16+32+64+128 = 255).
 */

// Constructor that converts an int number to the corresponding fixed-point value.
// The fractional bits value is initialized to 8.
Fixed::Fixed(const int number)// {
	: _frac_bit(8), _fixed_point_value(number << _frac_bit) {
	std::cout << "Int constructor called" << std::endl;
	int sign = _fixed_point_value < 0 ? -1 : 1;
	this->_fixed_point_value = (number << _frac_bit) * sign;
	return ;
}

/* ########################################################################## */

// Copy assignment operator
// Initializes an existing object to the value supplied by another existing object.
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* Also works:
		 * this->_fixed_point_value = rhs.getRawBits();
		 * or
		 * this->_fixed_point_value = rhs._fixed_point_vaue;
		 */
		this->setRawBits(rhs.getRawBits());
		// if we had some raw pointers on the class we would need to deal with
		// the memory here, i.e. deleting the current memory and allocation new
		// space for the rhs whole instance or specific member(s), then copy what
		// is inside the rhs instance into the memory that was just cleaned from
		// this current instance.
	}
	return *this;// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3.
}

/* ########################################################################## */

// The 6 comparison (binary) operators: >, <, >=, <=, == and !=.
// https://en.cppreference.com/w/cpp/language/operator_comparison
bool Fixed::operator>(const Fixed& rhs) const {
	std::cout << "Comparison > operator called" << std::endl;
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& rhs) const {
	std::cout << "Comparison < operator called" << std::endl;
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	std::cout << "Comparison >= operator called" << std::endl;
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	std::cout << "Comparison <= operator called" << std::endl;
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& rhs) const {
	std::cout << "Comparison == operator called" << std::endl;
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	std::cout << "Comparison != operator called" << std::endl;
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}

/* ########################################################################## */

// An overload of the insertion («) operator that inserts a floating-point
// representation of the fixed-point number into the output stream object passed as parameter
std::ostream& operator<<(std::ostream& output, const Fixed& rhs) {
	output << GREEN << rhs.toFloat() << RESET;
	return output;
}

/* ########################################################################## */

/* The conversion from the fixed point value to int or float is done by
 * shifting _frac_bit times to the right (>>) the fixed point value (binary).
 *
 * to int: just shifting is enough.
 * to float: a workaround has to be done to get a float number (with the decimals).
 *
 * >> means to do a division by the fractional bits (in this case as the _frac_bits
 * is always 8, so the division will be by 2^8 = 256 (1+2+4+8+16+32+64+128 = 255).
 */

// Converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
	int sign = _fixed_point_value < 0 ? -1 : 1;
	//std::cout << "\033[0;31m" << this->_fixed_point_value << " as fixed point value and as int: " << "\033[0m";
	return (this->_fixed_point_value >> this->_frac_bit) * sign;
}

// Converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
	int sign = _fixed_point_value < 0 ? -1 : 1;

	/* return (float)(this->_fixed_point_value >> this->_frac_bit) * sign;
	 * This will not print the franciton part. A workaround has to be done so
	 * the return can be really of type float (with the decimals). */

	std::cout << "\033[0;35m" << this->_fixed_point_value << " as fixed point value and as float: " << "\033[0m";
	// https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html
	return (float)this->_fixed_point_value / std::pow(2, this->_frac_bit) * sign;
	//return (float)this->_fixed_point_value / (float)(1 << this->_frac_bit) * sign; // Also works (1<<frac_bit = 256 = 100000000)
}

/* ########################################################################## */

// returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_value;
}

// sets the raw value of the fixed-point value.
void Fixed::setRawBits(const int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}
