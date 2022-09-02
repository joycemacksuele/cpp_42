/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/02 14:38:55 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>

/* ########################################################################## */

// Default constructor
Bureaucrat::Bureaucrat(void)
	: _name("Bureaucrat") {
	std::cout << GREEN << "Bureaucrat" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Overloaded constructor
Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
	: _name(name) {
	std::cout << GREEN << "Bureaucrat" << RESET << " Overloaded constructor called" << std::endl;
	throwError(grade);
	return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << GREEN << "Bureaucrat" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << GREEN << "Bureaucrat" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->setGrade(rhs.getGrade());
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << RED << "Bureaucrat" << RESET << " Destructor called" << std::endl << std::endl;
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

void Bureaucrat::throwError(const unsigned int& grade) {
	if (grade < _highestGrade) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > _lowestGrade) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		setGrade(grade);
	}
}

void Bureaucrat::incrementGrade() {
	throwError(getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
	throwError(getGrade() + 1);
}

void Bureaucrat::signForm(const bool& isSigned, const std::string& formName, const unsigned int& gradeToSignForm) const {
	//  If the form got signed, it will print:
	std::cout << std::endl;
	if (isSigned) {
		std::cout << GREEN << getName() << " signed " << formName << "! " << RESET << \
		"(The Bureaucrat's grade (" << getGrade() << ") is higher or equal than the required grade to sign (" << \
		gradeToSignForm << "))." << std::endl;
	} else {
		std::cout << YELLOW << getName() << " could't sign " << formName << " because its grade (" << \
		getGrade() << ") is too low. The Grade necessary to sign the form was: " << \
		gradeToSignForm << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	//  If the form got executed, it will print:
	std::cout << std::endl;
	if (form.getIsExecuted() && form.getIsSigned()) {
		std::cout << GREEN << getName() << " executed " << form.getFormName() << "! " << RESET << \
		"(The Bureaucrat's grade (" << getGrade() << ") is higher or equal than the required grade to execute (" << \
		form.getGradeToExecute() << ")." << std::endl;
	} else if (form.getIsSigned() == true) {
		std::cout << YELLOW << getName() << " could't execute " << form.getFormName() << \
		" because its grade (" << getGrade() << ") is too low. The Grade necessary to execute the form was: " << \
		form.getGradeToExecute() << RESET << std::endl;
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& rhs) {
	outputStream << std::endl << CYAN << rhs.getName() << ", bureaucrat grade ";
	std::cout << rhs.getGrade() << RESET << std::endl;
	return outputStream;
}

/* ########################################################################## */
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException -> The grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException -> The grade is too high";
}
