/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/02 14:39:45 by jfreitas      ########   odam.nl         */
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
	std::cout << RED << "AForm" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
const std::string& AForm::getFormName() const {
	return this->_formName;
}

void AForm::setFormName(const std::string& formName) {
	this->_formName = formName;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

bool AForm::getIsExecuted() const {
	return this->_isExecuted;
}

const unsigned int& AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

void AForm::setGradeToSign(const unsigned int& gradeToSign) {
	this->_gradeToSign = gradeToSign;
}

const unsigned int& AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::setGradeToExecute(const unsigned int& gradeToExecute) {
	this->_gradeToExecute = gradeToExecute;
}

const unsigned int& AForm::getHighestGrade() const {
	return this->_highestGrade;
}

void AForm::setHighestGrade(const unsigned int& highestGrade) {
	this->_highestGrade = highestGrade;
}

/* ########################################################################## */

void AForm::throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute) {
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade) {
		throw AForm::GradeTooHighException();
	} else if (gradeToSign > _gradeToSign || gradeToExecute > _gradeToSign) {
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

bool AForm::requirementsToExecute(const Bureaucrat& executor) {
	if (getIsSigned()) {
		if (executor.getGrade() < getHighestGrade()) {
			throw AForm::GradeTooHighException();
		} else if (executor.getGrade() > getGradeToExecute()) {
			throw AForm::GradeTooLowException();
		} else if (executor.getGrade() <= getGradeToExecute() ) {
			_isExecuted = true;
			return true;
		}
	}
	return false;
}

/* ########################################################################## */
const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException -> The grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException -> The grade is too high";
}
