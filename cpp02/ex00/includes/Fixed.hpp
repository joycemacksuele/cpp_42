/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/12 11:47:20 by jfreitas      ########   odam.nl         */
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

class Fixed {

	public:
		Fixed(void);// Default (no args) constructor
		Fixed(const Fixed &src);// Copy constructor
		Fixed& operator=(const Fixed &rhs);// Copy assignment operator
		~Fixed(void);// Destructor

		int		getRawBits(void) const;// returns the raw value of the fixed-point value.
		void	setRawBits(const int raw);// sets the raw value of the fixed-point number.

	/* _varNmae -> convention to remember that this variable is private */
	private:
		int					_number;// the fixed-point number value.
		static const int	_fractionalBit = 8;// the number of fractional bits. Its value will always be the integer literal 8.

};

#endif
