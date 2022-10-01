/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/01 11:26:35 by jfreitas      ########   odam.nl         */
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
	std::cout << RED << "ShrubberyCreationForm" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
/* ########################################################################## */

void ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	try {
		if (requirementsToExecute(executor)) {
			std::string fileName = _target + "_shrubbery";
			std::ofstream file(fileName);
			file << "\n\
		               ,@@@@@@@,\n\
		       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
		    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
		   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\n\
		   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\n\
		  %&&%/ %&%%&&@@\\ V /@@` `88\\8 `/88.\n\
		  `&%\\ ` /%&'    |.|        \\ '|8\n\
		       |o|        | |         | |\n\
		       |.|        | |         | |\n\
		    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_.form\n\n";
			file.close();
		} else {
			throw std::string(executor.getName() + " could't execute " + getFormName() +
			" because this form was not signed");
		}
	} catch (const std::exception& e) {
		throw ;
	}
}
