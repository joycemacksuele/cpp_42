/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/10 11:56:10 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Copy constructor:
// When objects are copied, cpp must create a new object from an existing object.
// Objectd can be copied by being passed as a paremeter or being returned from a function (by value),
// or by being constructed based on another object of the same class.
// cpp provides a compiler-defined copy constructor if you don't.
// It is most useful to have a copy constructor if your class has raw pointer, since
// the compiler-generated copy constructor won't copy the value/data that the pointer is point to,
// it will copy only the pointer.
// 
class Fixed {

	public:
		Fixed(void);// Default (no args) constructor
		Fixed(const Fixed &src);// Copy constructor
		Fixed& operator=(const Fixed &src);// Copy assignment operator
		~Fixed(void);// Destructor

		int		getRawBits(void) const;// returns the raw value of the fixed-point value.
		void	setRawBits(const int raw);// sets the raw value of the fixed-point number.

	/* _varNmae -> convention to remember that this variable is private */
	private:
		int					_number;// the fixed-point number value.
		static const int	_fractionalBit = 8;// the number of fractional bits. Its value will always be the integer literal 8.

};

#endif
