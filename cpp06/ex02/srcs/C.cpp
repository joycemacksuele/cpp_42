/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   C.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:36:00 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <C.hpp>

// Destructor
C::~C(void) {
	std::cout << RED << "C" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
