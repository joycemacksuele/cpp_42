/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/06/06 17:36:02 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	//Fixed const	c( Fixed( 2 ) / Fixed( 3 ) );

	std::cout << "a: " << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	
	std::cout << "b: " << b << std::endl;
	//std::cout << "c: " << c << std::endl;

	std::cout << "max(a,b): " << Fixed::max( a, b ) << std::endl;
	//std::cout << "min(a,c): " << Fixed::min( a, c ) << std::endl;

	return 0;
}
