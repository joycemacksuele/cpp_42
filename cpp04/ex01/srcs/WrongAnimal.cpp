/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 10:03:45 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/* ########################################################################## */

// Default constructor
WrongAnimal::WrongAnimal(void) 
	: type("WrongAnimal") {
	std::cout << GREEN << "WrongAnimal" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << GREEN << "WrongAnimal" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << GREEN << "WrongAnimal" << RESET << " Copy assignment operator called" << std::endl;
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
WrongAnimal::~WrongAnimal(void) {
	std::cout << YELLOW << "WrongAnimal" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::setType(const std::string& animalType) {
	type = animalType;
}

/* ########################################################################## */

// as its not virtual, won't be overriten by the child class
void WrongAnimal::makeSound() const {
	std::cout << "Wrong gnarrg.g.g.g?" << std::endl;

}

Brain* WrongAnimal::getBrain() const {// virtual method to be overriten by a child class
	return 0;
}
