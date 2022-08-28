/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/28 17:47:46 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

/* ########################################################################## */

// Default constructor
AForm::AForm(void)
	: _formName("Standard form"), _isSigned(false) {
	std::cout << GREEN << "AForm" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Overloaded constructor
AForm::AForm(const std::string& formName, const unsigned int& gradeToSign, const unsigned int& gradeToExecute)
	: _formName(formName), _isSigned(false) {
	std::cout << GREEN << "AForm" << RESET << " Overloaded constructor called" << std::endl;
	throwError(gradeToSign, gradeToExecute);
	return ;
}

// Copy constructor
AForm::AForm(const AForm &src) {
	std::cout << GREEN << "AForm" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& rhs) {
	std::cout << GREEN << "AForm" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());

	}
	return *this;
}

// Destructor
AForm::~AForm(void) {
	std::cout << std::endl << YELLOW << "AForm" << RESET << " Destructor called" << std::endl << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
const std::string& AForm::getFormName() const {
	return this->_formName;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

const unsigned int& AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

const unsigned int& AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::setGradeToSign(const unsigned int& gradeToSign) {
	this->_gradeToSign = gradeToSign;
}

void AForm::setGradeToExecute(const unsigned int& gradeToExecute) {
	this->_gradeToExecute = gradeToExecute;
}

/* ########################################################################## */

void AForm::throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute) {
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade) {
		throw AForm::GradeTooHighException();
	} else if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade) {
		throw AForm::GradeTooLowException();
	} else {
		setGradeToSign(gradeToSign);
		setGradeToExecute(gradeToExecute);
	}
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		_isSigned = true;
		bureaucrat.signForm(_isSigned, this->getFormName(), this->getGradeToSign());
	} else {
		bureaucrat.signForm(_isSigned, this->getFormName(), this->getGradeToSign());
		throw AForm::GradeTooLowException();
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const AForm& rhs) {
	bool isSigned = false;
	if (rhs.getIsSigned()) {
		isSigned = true;
	}
	outputStream << std::endl << CYAN << \
	"AForm: " << rhs.getFormName() << std::endl << \
	"Is Signed: " << std::boolalpha << isSigned << std::endl << \
	"Grade required to sign is: " << rhs.getGradeToSign() << std::endl << \
	"Grade required to execute is: " << rhs.getGradeToExecute() << RESET << std::endl;
	return outputStream;
}

/* ########################################################################## */
const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException -> The grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException -> The grade is too high";
}
