/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 17:04:06 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 12:26:45 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/* ########################################################################## */

// Default constructor
ScavTrap::ScavTrap(void)  {
	set_hitPoints(100);
	set_energyPoints(50);
	set_attackDamage(20);
	std::cout << YELLOW << "ScavTrap" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
ScavTrap::ScavTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage)// {
	: ClapTrap(name) {
	// Obs.: The value of a member variable can only be set in a member initializer
	// list of a constructor belonging to the same class as the variable.
	std::cout << YELLOW << "ScavTrap" << RESET << " Overloaded constructor called (with 1 or 4 parameter)" << std::endl;
	// private members of a parent class are still private (no direct access) even
	// if it was publicly inherited.
	set_hitPoints(hitPoints);
	set_energyPoints(energyPoints);
	set_attackDamage(attackDamage);
	return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ClapTrap &src) {
	std::cout << YELLOW << "ScavTrap" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ClapTrap& rhs) {
	std::cout << YELLOW << "ScavTrap" << RESET << " Copy assignment operator called" << std::endl;
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
ScavTrap::~ScavTrap(void) {
	std::cout << YELLOW << "ScavTrap" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

// An overload of the insertion («) operator that inserts a floating-point
// representation of the fixed-point number into the output stream object passed as parameter
/*std::ostream& operator<<(std::ostream& output, const ScavTrap& rhs) {
	std::cout << GREEN;
	std::cout << rhs.get_name() << ": current Hit Points is " << rhs.get_hitPoints() << RESET << " (Nb + <amount> for repair)" << std::endl;
	std::cout << GREEN;
	std::cout << rhs.get_name() << ": current Energy Points is " << rhs.get_energyPoints() << RESET << " (Nb - 1 per attack and/or repair)" << std::endl;
	std::cout << RESET;
	return output;
}*/

/* ########################################################################## */

void ScavTrap::attack(const std::string& target) {
	if (this->get_energyPoints() <= 0 || this->get_hitPoints() <= 0) {
		std::cout << BLUE << this->get_name() << " has no Energy Points or Hit Points leftm so it can't attack." << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "ScavTrap " << this->get_name() << ": attacks " << target << ", ";
	std::cout << "causing " << this->get_attackDamage() << " Points of damage on its Hit Points!" << RESET << std::endl;

	// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
	ScavTrap targetScavTrap(target);
	targetScavTrap.takeDamage(this->get_attackDamage());
	if (targetScavTrap.get_energyPoints() <= 0 || targetScavTrap.get_hitPoints() <= 0) {
		std::cout << BLUE << targetScavTrap.get_name() << " has no Energy Points or Hit Points left." << RESET << std::endl;
	}
	// Attacking costs 1 energy point.
	this->set_energyPoints(this->get_energyPoints() - 1);

	// output to keep track
	//std::cout << *this; -> this won't work since public members of the base/parent/inherited
	// class (ClapTrap) becomes the private members of the derived/child (ScavTrap) class.
	// So the getters and setters used on the insertion operator in this example are now private members of ScavTrap.
	std::cout << GREEN;
	std::cout << this->get_name() << ": current Hit Points is " << this->get_hitPoints() << RESET << " (Nb + <amount> for repair)" << std::endl;
	std::cout << GREEN;
	std::cout << this->get_name() << ": current Energy Points is " << this->get_energyPoints() << RESET << " (Nb - 1 per attack and/or repair)" << std::endl;
	std::cout << RESET;
}

void	ScavTrap::guardGate() {
	std::cout << YELLOW << "ScavTrap " << this->get_name() << ": is now in Gate keeper mode." <<  RESET << std::endl;
	this->beRepaired(5);
}
