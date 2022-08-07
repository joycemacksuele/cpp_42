/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 18:15:07 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Default constructor
AAnimal::AAnimal(void) {
	//: type("Animal") {
	std::cout << GREEN << "Animal" << RESET << " Default constructor called" << std::endl;
	this->type = new std::string("Animal");
	return ;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& src) {
	std::cout << GREEN << "Animal" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << GREEN << "Animal" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		delete this->type;
		this->type = new std::string(rhs.getType());
		this->setType(rhs.getType());
	}
	return *this;
}

// Destructor
AAnimal::~AAnimal(void) {
	std::cout << YELLOW << "Animal" << RESET << " Destructor called" << std::endl;
	delete this->type;
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& AAnimal::getType() const {
	return *this->type;
}

void AAnimal::setType(const std::string& animalType) {
	*this->type = animalType;
}

/* ########################################################################## */

//void AAnimal::makeSound() const {// virtual method to be overriten by a child class
//	std::cout << "gnarrg.g.g.g?" << std::endl;
//}

Brain* AAnimal::getBrain() const {// virtual method to be overriten by a child class
	return 0;
}
