/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 15:43:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Default constructor
Brain::Brain(void) { 
	std::cout << GREEN << "Brain" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Brain::Brain(const Brain& src) {
	std::cout << GREEN << "Brain" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Brain& Brain::operator=(const Brain& rhs) {
	std::cout << GREEN << "Brain" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		int i = 0;
		while (i < this->_number_of_ideas) {
			this->ideas[i] = rhs.ideas[i];
			i++;
		}
	}
	return *this;
}

// Destructor
Brain::~Brain(void) {
	std::cout << YELLOW << "Brain" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
