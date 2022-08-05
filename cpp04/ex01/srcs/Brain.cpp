/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/05 11:11:40 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Default constructor
Brain::Brain(void) { 
	std::cout << GREEN << "Brain" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
/*Brain::Brain(const std::string& type) {
	std::cout << GREEN << "Brain" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	return ;
}*/

// Copy constructor
Brain::Brain(const Brain& src) {
	std::cout << GREEN << "Brain" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Brain& Brain::operator=(const Brain& rhs) {
	std::cout << GREEN << "Brain" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		int i = 0;
		while (i < this->_number_of_ideas) {
			this->ideas[i] = rhs.ideas[i];
			i++;
		}
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
Brain::~Brain(void) {
	std::cout << YELLOW << "Brain" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
