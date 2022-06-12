/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/06/12 20:36:36 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* ########################################################################## */

// Default constructor
ClapTrap::ClapTrap(void) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Constructor with one parameter
ClapTrap::ClapTrap(const std::string name)// {
	: _name(name) {
	std::cout << "Overloaded constructor called (with one parameter)" << std::endl;
	return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal without
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
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

void ClapTrap::set_name(const std::string name) {
	_name = name;
}

void ClapTrap::set_hitPoints(const unsigned int hitPoints) {
	_hitPoints = hitPoints;
}

void ClapTrap::set_energyPoints(const unsigned int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::set_attackDamage(const unsigned int attackDamage) {
	_attackDamage = attackDamage;
}

/* ########################################################################## */

// An overload of the insertion («) operator that inserts a floating-point
// representation of the fixed-point number into the output stream object passed as parameter
std::ostream& operator<<(std::ostream& output, const ClapTrap& rhs) {
	std::cout << GREEN;
	std::cout << rhs.get_name() << " current Hit Points: " << rhs.get_hitPoints() << std::endl;
	std::cout << rhs.get_name() << " current Energy Points: " << rhs.get_energyPoints() << std::endl;
	std::cout << RESET;
	return output;
}

/* ########################################################################## */

void ClapTrap::attack(const std::string& target) {
	std::cout << YELLOW << "ClapTrap " << this->get_name() << " attacks " << target << ", ";
	std::cout << "causing " << this->get_attackDamage() << " Hit Points of damage!" << RESET << std::endl;

	// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
	ClapTrap targetClapTrap(target);
	targetClapTrap.takeDamage(this->get_attackDamage());
	// Attacking costs 1 energy point 
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
	std::cout << GREEN << "ClapTrap " << this->get_name() << " repared itself." << RESET << std::endl;
	// When ClapTrap repairs itself, it gets <amount> hit points back.
	this->set_hitPoints(this->get_hitPoints() + amount);
	// repairing costs 1 energy point.
	this->set_energyPoints(this->get_energyPoints() - 1);//--(*this)??

	// output to keep track
	std::cout << *this;
}

/* ########################################################################## */

// The 6 comparison (binary) operators: >, <, >=, <=, == and !=.
// https://en.cppreference.com/w/cpp/language/operator_comparison
/*bool ClapTrap::operator>(const ClapTrap& rhs) const {
	std::cout << "Comparison > operator called" << std::endl;
	if (this->_hitPoints > rhs._hitPoints)
		return true;
	return false;
}

bool ClapTrap::operator<(const ClapTrap& rhs) const {
	std::cout << "Comparison < operator called" << std::endl;
	if (this->_hitPoints < rhs._hitPoints)
		return true;
	return false;
}

bool ClapTrap::operator>=(const ClapTrap& rhs) const {
	std::cout << "Comparison >= operator called" << std::endl;
	if (this->_hitPoints >= rhs._hitPoints)
		return true;
	return false;
}

bool ClapTrap::operator<=(const ClapTrap& rhs) const {
	std::cout << "Comparison <= operator called" << std::endl;
	if (this->_hitPoints <= rhs._hitPoints)
		return true;
	return false;
}

bool ClapTrap::operator==(const ClapTrap& rhs) const {
	std::cout << "Comparison == operator called" << std::endl;
	if (this->_hitPoints == rhs._hitPoints)
		return true;
	return false;
}

bool ClapTrap::operator!=(const ClapTrap& rhs) const {
	std::cout << "Comparison != operator called" << std::endl;
	if (this->_hitPoints != rhs._hitPoints)
		return true;
	return false;
}*/

/* ########################################################################## */

// The 4 arithmetic (binary) operators: +, -, *, and /.
// https://en.cppreference.com/w/cpp/language/operator_arithmetic
/*ClapTrap ClapTrap::operator+(const ClapTrap& rhs) const {
	std::cout << "Arithmetic + operator called" << std::endl;
	ClapTrap lhs;
	lhs._attackDamage += rhs._attackDamage;
	return lhs;
	//return ClapTrap(this->_attackDamage + rhs._attackDamage );//had to have another overloaded contructor
}

ClapTrap ClapTrap::operator-(const ClapTrap& rhs) const {
	std::cout << "Arithmetic - operator called" << std::endl;
	ClapTrap lhs;
	lhs._attackDamage -= rhs._attackDamage;
	return lhs;
	//return ClapTrap(this->_attackDamage - rhs._attackDamage );//had to have another overloaded contructor
}

ClapTrap ClapTrap::operator*(const ClapTrap& rhs) const {
	std::cout << "Arithmetic * operator called" << std::endl;
	ClapTrap lhs;
	lhs._attackDamage *= rhs._attackDamage;
	return lhs;
	//return ClapTrap(this->_attackDamage * rhs._attackDamage );//had to have another overloaded contructor
}

ClapTrap ClapTrap::operator/(const ClapTrap& rhs) const {
	std::cout << "Arithmetic / operator called" << std::endl;
	ClapTrap lhs;
	lhs._attackDamage /= rhs._attackDamage;
	return lhs;
	//return ClapTrap(this->_attackDamage / rhs._attackDamage );//had to have another overloaded contructor
}*/

/* ########################################################################## */

/* The 4 (unary) increment/decrement
 * https://en.cppreference.com/w/cpp/language/operator_incdec
 * The post have an int argument "artificially" added so it can be differentiated from the pre ones.
 * https://stackoverflow.com/questions/15244094/overloading-for-both-pre-and-post-increment */

//  Attacking and repairing (methods) cost 1 energy point each
/*ClapTrap& ClapTrap::operator++() {
	std::cout << "Arithmetic ++ pre-increment operator called" << std::endl;
	this->_energyPoints += 1;
	return *this;
}

ClapTrap ClapTrap::operator++(int) {
	std::cout << "Arithmetic post-increment ++ operator called" << std::endl;
	ClapTrap lhs(*this);
	operator++();//calls the pre-increment to this instance
	//this->_energyPoints += 1; or ++(*this) also works
	return lhs;//returns the copy of this instance before it was incremented.
}

ClapTrap& ClapTrap::operator--() {
	std::cout << "Arithmetic -- pre-decrement operator called" << std::endl;
	this->_energyPoints -= 1;
	return *this;
}

ClapTrap ClapTrap::operator--(int) {
	std::cout << "Arithmetic post-decrement -- operator called" << std::endl;
	ClapTrap lhs(*this);
	operator--();//calls the pre-decrement to this instance
	//this->_energyPoints -= 1; or --(*this) also works
	return lhs;//returns the copy of this instance before it was incremented.
}*/
