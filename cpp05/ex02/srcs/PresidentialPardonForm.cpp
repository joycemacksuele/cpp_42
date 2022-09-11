/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/11 15:38:22 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

/* ########################################################################## */

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void)
	: _target("Standard target") {
	std::cout << GREEN << "PresidentialPardonForm" << RESET << " Default constructor called" << std::endl;
	setFormName("PresidentialPardonForm");
	setHighestGrade(1);
	setGradeToSign(25);
	setGradeToExecute(5);
	return ;
	}

// Overloaded constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: _target(target) {
	std::cout << GREEN << "PresidentialPardonForm" << RESET << " Overloaded constructor called" << std::endl;
	setFormName("PresidentialPardonForm");
	setHighestGrade(1);
	setGradeToSign(145);
	setGradeToExecute(137);
	return ;
	}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {
	std::cout << GREEN << "PresidentialPardonForm" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
template<typename T>
T& PresidentialPardonForm::operator=(const T& rhs) {
	std::cout << GREEN << "PresidentialPardonForm" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << std::endl << RED << "PresidentialPardonForm" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
/* ########################################################################## */

void PresidentialPardonForm::execute(const Bureaucrat& executor) {
	try {
		if (requirementsToExecute(executor)) {
			std::cout << std::endl;
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
		} else {
			throw std::string(getFormName() + "'s target: " + _target + "could not be pardoned");
		}
	} catch (const std::exception& e) {
		throw ;
	}
	sleep(1);
}
