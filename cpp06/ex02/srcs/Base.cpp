/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:54 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 16:52:37 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>

// Destructor
Base::~Base(void) {
	std::cout << RED << "Base" << RESET;
	std::cout << " Destructor called" << std::endl << std::endl;
	return ;
}
