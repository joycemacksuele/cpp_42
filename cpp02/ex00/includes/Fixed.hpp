/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/03 10:27:44 by jfreitas      ########   odam.nl         */
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
		Fixed(void);// Default constructor
		Fixed(Fixed const &src);// Copy constructor
		Fixed& operator=(Fixed const &src);// Copy assignment operator
		~Fixed(void);// Destructor

		int		getRawBits(void) const;// returns the raw value of the fixed-point value.
		void	setRawBits(int const raw);// sets the raw value of the fixed-point number.

	/* _varNmae -> convention to remember that this variable is private */
	private:
		int					_number;
		static const int	_fractionalBit = 8;

};

#endif
