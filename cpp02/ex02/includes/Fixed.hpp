/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/06/06 18:06:23 by jfreitas      ########   odam.nl         */
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
		Fixed(const float numberfloat);// Overloade constructor (with one float param)
		Fixed(const Fixed &src);// Overloaded Copy constructor
		Fixed& operator=(const Fixed& rhs);// Copy assignment operator
		// Important to return a reference to the class since we don't want a deep copy). ex: s2 = s1 is actually s2.operator=(s1);
		/* - Good to know: Move assignment operator is like the Copy one but the parameter
		 *   is a non const (since we will change it by null-ing it) r-value reference (aka ClassName&& rhs).
		 * - Move operator will make the current instance point to the value the rhs is pointing to,
		 *   then null the rhs pointer (so rhs pointer is lost/not accessible anymore).
		 * - Copy operator will delete what is inside the current instance, allocate a new
		 *   necessary space to it and copy what is inside the rhs to this memory just allocated
		 *   on the current instance (so the rhs pointer is still accessibe and still with the value
		 *   it had before (aka: now we have 2 addresses with the sam evalue in it)).
		 */
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
		// The 4 arithmetic (binary) operators: +, -, *, and /.
		// https://en.cppreference.com/w/cpp/language/operator_arithmetic
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;
		// The 4 (unary) increment/decrement 
		// https://en.cppreference.com/w/cpp/language/operator_incdec
		Fixed&	operator++();// ++var (pre-increment)
		Fixed	operator++(int);// var++ (post-increment)
		Fixed&	operator--();// --var (pre-decrement)
		Fixed	operator--(int);// var-- (post-decrement)

		static Fixed&		min(Fixed& lhs, Fixed& rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

	/* _varNmae -> convention to remember that this variable is private */
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
