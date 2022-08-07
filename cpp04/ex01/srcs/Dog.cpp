/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 16:00:28 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog(void) {
	std::cout << GREEN << "Dog" << RESET << " Default constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
	return ;
}

// Copy constructor
Dog::Dog(const Dog& src) {
	std::cout << GREEN << "Dog" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& rhs) {
	std::cout << GREEN << "Dog" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, doing a deep copy. i.e.:
		 */

		// deleting the current memory (it was allocated on the constructor)
		delete this->type;
		// allocation new space for the rhs whole instance or specific member(s)
		this->type = new std::string(rhs.getType());
		this->_brain = new Brain();
		// then copy what is inside the rhs instance into the memory that was
		// just cleaned from this current instance.
		*this->_brain = *rhs._brain;
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
Dog::~Dog(void) {
	std::cout << YELLOW << "Dog" << RESET << " Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/* ########################################################################## */

//virtual method form the parent class, so this one will be executed instead
void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}

/* ########################################################################## */

//virtual method form the parent class, so this one will be executed instead
Brain* Dog::getBrain() const {
	return this->_brain;
}
