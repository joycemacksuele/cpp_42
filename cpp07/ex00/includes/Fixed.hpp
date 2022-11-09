/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/11/09 14:20:30 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Fixed {
	public:
		Fixed(void);// Default (no args) constructor
		Fixed(const int numberInt);// Overloaded cnstructor (with one int param)
		Fixed(const Fixed &src);// Overloaded Copy constructor
		Fixed& operator=(const Fixed& rhs);// Copy assignment operator
		~Fixed(void);// Destructor

		int		toInt(void) const;// that converts the fixed-point value to an integer value.
		float	toFloat(void) const;// converts the fixed-point value to a floating-point value.

		// The 6 comparison (binary) operators: >, <, >=, <=, == and !=.
		// https://en.cppreference.com/w/cpp/language/operator_comparison
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

	private:
		int		getRawBits(void) const;// returns the raw value of the fixed-point value.
		void	setRawBits(const int raw);// sets the raw value of the fixed-point number.

		// A fixed-point number is a representation of a real number using a
		// certain number of bits of a type for the integer part, and the
		// remaining bits of the type for the fractional part.
		const int	_frac_bit;// the number of fractional bits. Its value will always be the integer literal 8.
		int			_fixed_point_value;// the fixed-point value (whole number without fraction).

};
std::ostream& operator<<(std::ostream &stream, const Fixed &rhs);// Stream operator

#endif
