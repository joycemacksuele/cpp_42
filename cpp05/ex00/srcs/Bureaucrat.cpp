/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/12 17:43:50 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

/* ########################################################################## */

// Default constructor
Bureaucrat::Bureaucrat(void)
	: _name("Bureaucrat") {
		std::cout << GREEN << "Bureaucrat" << RESET << " Default constructor called" << std::endl;
		return ;
	}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
	: _name(name) {
		std::cout << GREEN << "Bureaucrat" << RESET << " Overloaded constructor called" << std::endl;
		if (grade < 1) {
			throw Bureaucrat::GradeTooHighException();
		} else if (grade > 150) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			this->setGrade(grade);
		}
		return ;
	}

// Constructor with one parameter
/*Bureaucrat::Bureaucrat(const std::string type) {
  std::cout << GREEN << "Bureaucrat" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
  return ;
  }*/

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << GREEN << "Bureaucrat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << GREEN << "Bureaucrat" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) { //checking for self assignmet (if the 2 instances are equal)
		/* if we had some raw pointers on the class we would need to deal with
		 * the memory here, i.e. deleting the current memory and allocation new
		 * space for the rhs whole instance or specific member(s), then copy what
		 * is inside the rhs instance into the memory that was just cleaned from
		 * this current instance.
		 */
		this->setGrade(rhs.getGrade());
	}
	// return the current instance by reference (the content of it, to allow chain assignment) as s1 = s2 = s3
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << YELLOW << "Bureaucrat" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

const unsigned int& Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(const unsigned int& grade) {
	this->_grade = grade;
}

/* ########################################################################## */

void Bureaucrat::incrementGrade() {
	if (getGrade() - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		setGrade(getGrade() - 1);
	}
}

void Bureaucrat::decrementGrade() {
	if (getGrade() + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		setGrade(getGrade() + 1);
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& rhs) {
	outputStream << std::endl << BLUE << rhs.getName() << ", bureaucrat grade ";
	std::cout << rhs.getGrade() << RESET << std::endl << std::endl;
	return outputStream;
}

/* ########################################################################## */
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException -> The grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException -> The grade is too high";
}
