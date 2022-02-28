/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/27 15:58:55 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _number( 0 ) {
	std::cout << "deefault constructor -> " << std::endl;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor -> " << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const {// returns the raw value of the fixed-point value.
}

void	Fixed::setRawBits( int const raw ) {// sets the raw value of the fixed-point number.
	std::cout << GREEN << raw << std::endl << RESET;
}
