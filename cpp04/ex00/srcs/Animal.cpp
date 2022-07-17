/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/17 18:54:08 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/* ########################################################################## */

// Default constructor
Animal::Animal(void) 
	: type("Any Animal") {
	std::cout << GREEN << "Animal" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
/*Animal::Animal(const std::string type) {
	std::cout << GREEN << "Animal" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	return ;
}*/

// Copy constructor
Animal::Animal(const Animal &src) {
	std::cout << GREEN << "Animal" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& rhs) {
	std::cout << GREEN << "Animal" << RESET << " Copy assignment operator called" << std::endl;
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
Animal::~Animal(void) {
	std::cout << GREEN << "Animal" << RESET << " Destructor called" << std::endl;
	delete [] this;
	return ;
}

/* ########################################################################## */
// getters and setters

std::string Animal::getType() const {
	return type;
}

void Animal::setType(std::string animalType) {
	type = animalType;
}

/* ########################################################################## */

void Animal::makeSound() const {
	std::cout << "gnarrg.g.g.g?" << std::endl;

}
