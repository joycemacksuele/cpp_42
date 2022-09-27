/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/24 14:36:21 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/27 17:12:58 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

/* ########################################################################## */

// Default constructor
Intern::Intern(void) {
	std::cout << GREEN << "Intern" << RESET << " Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Intern::Intern(const Intern &src) {
	std::cout << GREEN << "Intern" << RESET << " Copy constructor called" << std::endl;
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	std::cout << GREEN << "Intern" << RESET << " Copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
Intern::~Intern(void) {
	std::cout << RED << "Intern" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm* form = NULL;
	std::strcmp(formName.c_str(), "shrubbery creation") == 0 ?
			form = new ShrubberyCreationForm(target)
		: std::strcmp(formName.c_str(), "robotomy request") == 0 ?
			form = new RobotomyRequestForm(target)
		: std::strcmp(formName.c_str(), "presidential pardon") == 0 ?
			form = new PresidentialPardonForm(target)
		: NULL;
	form == NULL ?
		throw std::string("Wrong form name!") :
		std::cout << std::endl << CYAN << "Intern creates " << form->getFormName() << RESET << std::endl;
	//AForm* copyForm;
	//copyForm = form;
	//delete form;// check if leaks
	return form;
}
