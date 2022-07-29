/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 10:07:28 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

/* ########################################################################## */

// Default constructor
WrongCat::WrongCat(void) {
	std::cout << GREEN << "WrongCat" << RESET << " Default constructor called" << std::endl;
	this->setType("WrongCat");
	this->_brain = new Brain();
	return ;
}

// Constructor with one parameter
WrongCat::WrongCat(const std::string& type) {
	std::cout << GREEN << "Cat" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	this->setType(type);
	this->_brain = new Brain();
	return ;
}

// Copy constructor
/*WrongCat::WrongCat(const WrongCat &src) {
	std::cout << GREEN << "WrongCat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}*/

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << GREEN << "WrongCat" << RESET << " Copy assignment operator called" << std::endl;
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
		*this->_brain = *rhs._brain;
		this->setType(rhs.getType());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
WrongCat::~WrongCat(void) {
	std::cout << YELLOW << "WrongCat" << RESET << " Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/* ########################################################################## */

// as this method is not virtual in the parent class, this is not overriting it.
void WrongCat::makeSound() const {
	std::cout << "Wrong Miaw Miaw!" << std::endl;
}

/* ########################################################################## */

//virtual method form the parent class, so this one will be executed instead
Brain* WrongCat::getBrain() const {
	return this->_brain;
}
