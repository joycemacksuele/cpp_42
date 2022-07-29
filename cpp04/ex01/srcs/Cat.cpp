/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 19:22:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/* ########################################################################## */

// Default constructor
Cat::Cat(void) {
	std::cout << GREEN << "Cat" << RESET << " Default constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
	return ;
}

// Constructor with one parameter
Cat::Cat(const std::string& type) {
	std::cout << GREEN << "Dog" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	this->setType(type);
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
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, doing a deep copy. i.e.:
		 */

		// deleting the current memory (it was allocated on the constructor)
		//delete this->_brain;
		// allocation new space for the rhs whole instance or specific member(s)
		//this->_brain = new Brain(); // in this case, for the specific member _brain
		// then copy what is inside the rhs instance into the memory that was
		// just cleaned from this current instance.
		*this->_brain = *rhs.getBrain();
		this->setType(rhs.getType());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Copy assignment operator
// virtual operator from the parent class, so this one will be executed instead
Animal& Cat::operator=(const Animal& rhs) {
	std::cout << GREEN << "Animal overriten by Cat" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, doing a deep copy. i.e.:
		 */

		// deleting the current memory (it was allocated on the constructor)
		delete this->_brain;
		// allocation new space for the rhs whole instance or specific member(s)
		this->_brain = new Brain(); // in this case, for the specific member _brain
		// then copy what is inside the rhs instance into the memory that was
		// just cleaned from this current instance.
		*this->_brain = *rhs.getBrain();
		this->setType(rhs.getType());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
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
