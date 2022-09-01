/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/01 13:08:17 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

/* ########################################################################## */

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: _target("Standard target") {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Default constructor called" << std::endl;
	setFormName("ShrubberyCreationForm");
	setHighestGrade(1);
	setGradeToSign(145);
	setGradeToExecute(137);
	return ;
}

// Overloaded constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: _target(target) {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Overloaded constructor called" << std::endl;
	setFormName("ShrubberyCreationForm");
	setHighestGrade(1);
	setGradeToSign(145);
	setGradeToExecute(137);
	return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << std::endl << YELLOW << "ShrubberyCreationForm" << RESET << " Destructor called" << std::endl << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
/* ########################################################################## */

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		if (requirementsToExecute(executor)) {
			std::string fileName = _target + "_shrubbery";
			std::ofstream file(fileName);
			file << "  ,@@@@@@@,\
		       ,,,.   ,@@@@@@/@@,  .oo8888o.\
		    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\
		   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\
		   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\
		  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\
		  `&%\\ ` /%&'    |.|        \\ '|8'\
		       |o|        | |         | |\
		       |.|        | |         | |\
		    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
			file.close();
		}
	} catch (const std::exception& e) {
		throw e;
	}
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm& rhs) {
	bool isSigned = false;
	bool isExecuted = false;
	if (rhs.getIsSigned()) {
		isSigned = true;
	}
	if (rhs.getIsExecuted()) {
		isExecuted = true;
	}
	outputStream << std::endl << CYAN << \
	"ShrubberyCreationForm: " << std::endl << \
	"Grade required to sign is: " << rhs.getGradeToSign() << std::endl << \
	"Grade required to execute is: " << rhs.getGradeToExecute() << std::endl << \
	"Is Signed: " << std::boolalpha << isSigned << std::endl << \
	"Is executed: " << std::boolalpha << isExecuted << std::endl << RESET;

	return outputStream;
}
