/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:27:12 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/13 18:18:56 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <Bureaucrat.hpp>
#include <Form.hpp>



/* ########################################################################## */

// Default constructor
Form::Form(void)
	: _formName("Standard form"), _isSigned(false) {
	std::cout << GREEN << "Form" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Overloaded constructor
Form::Form(const std::string& formName, const unsigned int& gradeToSign, const unsigned int& gradeToExecute)
	: _formName(formName), _isSigned(false) {
	std::cout << GREEN << "Form" << RESET << " Overloaded constructor called" << std::endl;
	throwError(gradeToSign, gradeToExecute);
	return ;
}


// Copy constructor
Form::Form(const Form &src) {
	std::cout << GREEN << "Form" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Form& Form::operator=(const Form& rhs) {
	std::cout << GREEN << "Form" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());

	}
	return *this;
}

// Destructor
Form::~Form(void) {
	std::cout << std::endl << YELLOW << "Form" << RESET << " Destructor called" << std::endl << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
const std::string& Form::getFormName() const {
	return this->_formName;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

const unsigned int& Form::getGradeToSign() const {
	return this->_gradeToSign;
}

const unsigned int& Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::setGradeToSign(const unsigned int& gradeToSign) {
	this->_gradeToSign = gradeToSign;
}

void Form::setGradeToExecute(const unsigned int& gradeToExecute) {
	this->_gradeToExecute = gradeToExecute;
}

/* ########################################################################## */

void Form::throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute) {
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade) {
		throw Form::GradeTooHighException();
	} else if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade) {
		throw Form::GradeTooLowException();
	} else {
		setGradeToSign(gradeToSign);
		setGradeToExecute(gradeToExecute);
	}
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		_isSigned = true;
		bureaucrat.signForm(_isSigned, this->getFormName(), this->getGradeToSign());
	} else {
		bureaucrat.signForm(_isSigned, this->getFormName(), this->getGradeToSign());
		throw Form::GradeTooLowException();
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const Form& rhs) {
	bool isSigned = false;
	if (rhs.getIsSigned()) {
		isSigned = true;
	}
	outputStream << std::endl << CYAN << \
	"Form: " << rhs.getFormName() << std::endl << \
	"Is Signed: " << std::boolalpha << isSigned << std::endl << \
	"Grade required to sign is: " << rhs.getGradeToSign() << std::endl << \
	"Grade required to execute is: " << rhs.getGradeToExecute() << RESET << std::endl;
	return outputStream;
}

/* ########################################################################## */
const char* Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException -> The grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException -> The grade is too high";
}
