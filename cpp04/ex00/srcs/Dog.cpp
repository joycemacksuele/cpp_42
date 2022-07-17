/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/17 18:44:51 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/* ########################################################################## */

// Default constructor
Dog::Dog(void) {
	//: type("Dog") {
	std::cout << GREEN << "Dog" << RESET << " Default constructor called" << std::endl;
	setType("Dog");
	return ;
}

// Constructor with one parameter
/*Dog::Dog(const std::string type) {
	std::cout << GREEN << "Dog" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	return ;
}*/

// Copy constructor
Dog::Dog(const Dog &src) {
	std::cout << GREEN << "Dog" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& rhs) {
	std::cout << GREEN << "Dog" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal without
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
Dog::~Dog(void) {
	std::cout << GREEN << "Dog" << RESET << " Destructor called" << std::endl;
	delete [] this;
	return ;
}

/* ########################################################################## */

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;

}
