/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/28 18:12:46 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

/* ########################################################################## */

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Overloaded constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: _target(target) {
	std::cout << GREEN << "ShrubberyCreationForm" << RESET << " Overloaded constructor called" << std::endl;
	//throwError(gradeToSign, gradeToExecute);
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

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) {
	std::string fileName = _target + "_shrubbery";
	std::ofstream file(fileName);
	file << "  ,@@@@@@@,\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\
   ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\
   `&%\\ ` /%&'    |.|        \\ '|8'\
       |o|        | |         | |\
       |.|        | |         | |\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
	file.close();
}

