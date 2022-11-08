/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   D.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 15:01:39 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <D.hpp>

// Destructor
D::~D(void) {
	std::cout << RED << "D" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
