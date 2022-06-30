/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/06/30 13:09:27 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* ########################################################################## */

// Default constructor
ClapTrap::ClapTrap(void)
	: _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
ClapTrap::ClapTrap(const std::string name)// {
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
	return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << GREEN << "ClapTrap" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << GREEN << "ClapTrap" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal without
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		set_name(rhs._name);
		set_hitPoints(rhs.get_hitPoints());
		set_energyPoints(rhs.get_energyPoints());
		set_attackDamage(rhs.get_attackDamage());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << GREEN << "ClapTrap" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters

std::string ClapTrap::get_name() const {
	return _name;
}

unsigned int ClapTrap::get_hitPoints() const {
	return _hitPoints;
}

unsigned int ClapTrap::get_energyPoints() const {
	return _energyPoints;
}

unsigned int ClapTrap::get_attackDamage() const {
	return _attackDamage;
}

void ClapTrap::set_name(std::string name) {
	_name = name;
}

void ClapTrap::set_hitPoints(unsigned int hitPoints) {
	_hitPoints = hitPoints;
}

void ClapTrap::set_energyPoints(unsigned int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::set_attackDamage(unsigned int attackDamage) {
	_attackDamage = attackDamage;
}

/* ########################################################################## */

// An overload of the insertion («) operator that inserts a floating-point
// representation of the fixed-point number into the output stream object passed as parameter
std::ostream& operator<<(std::ostream& output, const ClapTrap& rhs) {
	std::cout << GREEN;
	std::cout << rhs.get_name() << ": current Hit Points is " << rhs.get_hitPoints() << RESET << " (Nb + <amount> for repair)" << std::endl;
	std::cout << GREEN;
	std::cout << rhs.get_name() << ": current Energy Points is " << rhs.get_energyPoints() << RESET << " (Nb - 1 per attack and/or repair)" << std::endl;
	std::cout << RESET;
	return output;
}

/* ########################################################################## */

void ClapTrap::attack(const std::string& target) {
	std::cout << YELLOW << "ClapTrap " << this->get_name() << ": attacks " << target << ", ";
	std::cout << "causing " << this->get_attackDamage() << " Points of damage on its Hit Points!" << RESET << std::endl;

	// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
	ClapTrap targetClapTrap(target);
	targetClapTrap.takeDamage(this->get_attackDamage());
	// Attacking costs 1 energy point.
	this->set_energyPoints(this->get_energyPoints() - 1);//--(*this)??

	// output to keep track
	std::cout << *this;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->set_hitPoints(this->get_hitPoints() - amount);

	// output to keep track
	std::cout << *this;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << GREEN << "ClapTrap " << this->get_name() << ": repared itself." << RESET << std::endl;
	// When ClapTrap repairs itself, it gets <amount> hit points back.
	this->set_hitPoints(this->get_hitPoints() + amount);
	// repairing costs 1 energy point.
	this->set_energyPoints(this->get_energyPoints() - 1);//--(*this)??

	// output to keep track
	std::cout << *this;
}
