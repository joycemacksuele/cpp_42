/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 16:10:38 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(void) {
	std::cout << GREEN << "Cat" << RESET << " Default constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
	return ;
}

// Copy constructor
Cat::Cat(const Cat& src) {
	std::cout << GREEN << "Cat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& rhs) {
	std::cout << GREEN << "Cat" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		delete this->type;
		this->type = new std::string(rhs.getType());
		this->_brain = new Brain();
		*this->_brain = *rhs.getBrain();
	}
	return *this;
}

// Destructor
Cat::~Cat(void) {
	std::cout << YELLOW << "Cat" << RESET << " Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/* ########################################################################## */

//virtual method from the parent class, so this one will be executed instead
void Cat::makeSound() const {
	std::cout << "Miaw Miaw!" << std::endl;
}

/* ########################################################################## */

//virtual method form the parent class, so this one will be executed instead
Brain* Cat::getBrain() const {
	return this->_brain;
}
