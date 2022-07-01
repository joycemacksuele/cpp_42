/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 17:04:06 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 13:00:29 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* ########################################################################## */

// Default constructor
FragTrap::FragTrap(void)  {
	set_hitPoints(100);
	set_energyPoints(100);
	set_attackDamage(30);
	std::cout << YELLOW << "FragTrap" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
FragTrap::FragTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage)// {
	: ClapTrap(name) {
	// Obs.: The value of a member variable can only be set in a member initializer
	// list of a constructor belonging to the same class as the variable.
	std::cout << YELLOW << "FragTrap" << RESET << " Overloaded constructor called (with 1 or 4 parameter)" << std::endl;
	// private members of a parent class are still private (no direct access) even
	// if it was publicly inherited.
	set_hitPoints(hitPoints);
	set_energyPoints(energyPoints);
	set_attackDamage(attackDamage);
	return ;
}

// Copy constructor
FragTrap::FragTrap(const ClapTrap &src) {
	std::cout << YELLOW << "FragTrap" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const ClapTrap& rhs) {
	std::cout << YELLOW << "FragTrap" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal without
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		set_name(rhs.get_name());
		set_hitPoints(rhs.get_hitPoints());
		set_energyPoints(rhs.get_energyPoints());
		set_attackDamage(rhs.get_attackDamage());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
FragTrap::~FragTrap(void) {
	std::cout << YELLOW << "FragTrap" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

void	FragTrap::highFivesGuys() {
	std::cout << YELLOW << "FragTrap " << this->get_name() << " wants to high-five not attack!" <<  RESET << std::endl;
}
