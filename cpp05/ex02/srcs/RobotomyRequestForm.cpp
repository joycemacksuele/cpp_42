/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/02 16:10:32 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

/* ########################################################################## */

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) 
	: _target("Standard target") {
	std::cout << GREEN << "RobotomyRequestForm" << RESET << " Default constructor called" << std::endl;
	setFormName("RobotomyRequestForm");
	setHighestGrade(1);
	setGradeToSign(72);
	setGradeToExecute(45);
	return ;
}

// Overloaded constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: _target(target) {
	std::cout << GREEN << "RobotomyRequestForm" << RESET << " Overloaded constructor called" << std::endl;
	setFormName("RobotomyRequestForm");
	setHighestGrade(1);
	setGradeToSign(145);
	setGradeToExecute(137);
	return ;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {
	std::cout << GREEN << "RobotomyRequestForm" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::cout << GREEN << "RobotomyRequestForm" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << std::endl << RED << "RobotomyRequestForm" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
/* ########################################################################## */

void RobotomyRequestForm::execute(const Bureaucrat& executor) {
	try {
		if (requirementsToExecute(executor)) {
            std::cout << _target << " has been robotomized!";
		} else {
			throw std::string("Robotomy failed for " + getFormName() << "'s target: " << _target);
		}
	} catch (const std::exception& e) {
		throw ;
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const RobotomyRequestForm& rhs) {
	outputStream << std::endl << CYAN << \
	"RobotomyRequestForm: " << std::endl << \
	"Grade required to sign is: " << rhs.getGradeToSign() << std::endl << \
	"Grade required to execute is: " << rhs.getGradeToExecute() << std::endl << \
	"Is Signed: " << std::boolalpha << rhs.getIsSigned() << std::endl << \
	"Is executed: " << std::boolalpha << rhs.getIsExecuted() << std::endl << RESET;

	return outputStream;
}
