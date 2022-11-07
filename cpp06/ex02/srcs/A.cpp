/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:34:12 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>

// Destructor
A::~A(void) {
	std::cout << RED << "A" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
