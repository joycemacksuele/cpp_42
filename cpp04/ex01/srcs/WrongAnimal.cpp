/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 15:57:18 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void) {
	std::cout << GREEN << "WrongAnimal" << RESET << " Default constructor called" << std::endl;
	this->type = new std::string("WrongAnimal");
	return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << GREEN << "WrongAnimal" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the standart copy assignment operator
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	std::cout << YELLOW << "WrongAnimal" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& WrongAnimal::getType() const {
	return *this->type;
}

void WrongAnimal::setType(const std::string& animalType) {
	*this->type = animalType;
}

/* ########################################################################## */

// as its not virtual, won't be overriten by the child class
void WrongAnimal::makeSound() const {
	std::cout << "Wrong gnarrg.g.g.g?" << std::endl;
}
