/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 12:03:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <A.hpp>

// Destructor
A::~A(void) {
	std::cout << RED << "A" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
