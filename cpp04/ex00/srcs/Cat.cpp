/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/24 12:22:01 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/* ########################################################################## */

// Default constructor
Cat::Cat(void) {
	//: type("Cat") {
	std::cout << GREEN << "Cat" << RESET << " Default constructor called" << std::endl;
	setType("Cat");
	return ;
}

// Copy constructor
Cat::Cat(const Cat &src) {
	std::cout << GREEN << "Cat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& rhs) {
	std::cout << GREEN << "Cat" << RESET << " Copy assignment operator called" << std::endl;
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
Cat::~Cat(void) {
	std::cout << YELLOW << "Cat" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

//virtual method form the parent class, so this one will be executed instead
void Cat::makeSound() const {
	std::cout << "Miaw Miaw!" << std::endl;
}
