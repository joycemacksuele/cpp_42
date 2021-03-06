/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/24 12:22:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

/* ########################################################################## */

// Default constructor
WrongCat::WrongCat(void) {
	//: type("WrongCat") {
	std::cout << GREEN << "WrongCat" << RESET << " Default constructor called" << std::endl;
	setType("WrongCat");
	return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &src) {
	std::cout << GREEN << "WrongCat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << GREEN << "WrongCat" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		setType(rhs.getType());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
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
