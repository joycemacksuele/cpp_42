/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   B.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:36:19 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <B.hpp>

// Destructor
B::~B(void) {
	std::cout << RED << "B" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
