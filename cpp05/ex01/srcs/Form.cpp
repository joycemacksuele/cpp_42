/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/12 18:17:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>


/* ########################################################################## */

// Default constructor
Form::Form(void)
	: _name("Form") {
		std::cout << GREEN << "Form" << RESET << " Default constructor called" << std::endl;
		return ;
	}

Form::Form(const std::string& name, const unsigned int& grade)
	: _name(name) {
		std::cout << GREEN << "Form" << RESET << " Overloaded constructor called" << std::endl;
		if (grade < 1) {
			throw Form::GradeTooHighException();
		} else if (grade > 150) {
			throw Form::GradeTooLowException();
		} else {
			this->setGrade(grade);
		}
		return ;
	}

// Constructor with one parameter
/*Form::Form(const std::string type) {
  std::cout << GREEN << "Form" << RESET << " Overloaded constructor called (with one parameter)" << std::endl;
  return ;
  }*/

// Copy constructor
Form::Form(const Form &src) {
	std::cout << GREEN << "Form" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Form& Form::operator=(const Form& rhs) {
	std::cout << GREEN << "Form" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->setGrade(rhs.getGrade());
	}
	return *this;
}

// Destructor
Form::~Form(void) {
	std::cout << YELLOW << "Form" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& Form::getName() const {
	return this->_name;
}

const unsigned int& Form::getGrade() const {
	return this->_grade;
}

void Form::setGrade(const unsigned int& grade) {
	this->_grade = grade;
}

/* ########################################################################## */

void Form::incrementGrade() {
	if (getGrade() - 1 < 1) {
		throw Form::GradeTooHighException();
	} else {
		setGrade(getGrade() - 1);
	}
}

void Form::decrementGrade() {
	if (getGrade() + 1 > 150) {
		throw Form::GradeTooLowException();
	} else {
		setGrade(getGrade() + 1);
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const Form& rhs) {
	outputStream << std::endl << BLUE << rhs.getName() << ", bureaucrat grade ";
	std::cout << rhs.getGrade() << RESET << std::endl << std::endl;
	return outputStream;
}

/* ########################################################################## */
const char* Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException -> The grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException -> The grade is too high";
}
