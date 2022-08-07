/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 16:11:56 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) {
	std::cout << GREEN << "WrongCat" << RESET << " Default constructor called" << std::endl;
	this->setType("WrongCat");
	return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &src) {
	std::cout << GREEN << "WrongCat" << RESET << " Copy constructor called" << std::endl;
	// deleting the current memory (it was allocated on the constructor), since we
	// the standart assignment operator won't allocate anything on these pointers
	delete src.type;
	delete this->type;
	*this = src; // this will call the copy assignment operator (in this case, default one)
}

// Destructor
WrongCat::~WrongCat(void) {
	std::cout << YELLOW << "WrongCat" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

// as this method is not virtual in the parent class, this is not overriting it.
void WrongCat::makeSound() const {
	std::cout << "Wrong Miaw Miaw!" << std::endl;
}
