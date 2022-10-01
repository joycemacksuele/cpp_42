/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                          :+:    :+:              */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:03:05 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/01 11:31:19 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

// Other option to play the alert sound:
// https://developer.apple.com/documentation/audiotoolbox/1405222-system_sounds/ksystemsoundid_userpreferredalert?language=objc
//#include <AudioToolbox/AudioServices.h>
//AudioServicesPlayAlertSound(kSystemSoundID_FlashScreen);

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
	setGradeToSign(72);
	setGradeToExecute(45);
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
	std::cout << RED << "RobotomyRequestForm" << RESET << " Destructor called" << std::endl;
	return ;
}

/* ########################################################################## */
// getters and setters
/* ########################################################################## */

void RobotomyRequestForm::execute(const Bureaucrat& executor) {
	try {
		if (requirementsToExecute(executor)) {
			std::cout << std::endl;
			sleep(1);
			std::cout << "~~ Drilling noises ~~" << std::endl;
			std::cout << "\007";
			std::cout.flush();
			std::cout << CYAN << _target << " has been robotomized!" << RESET << std::endl;
			std::cout << "\007";
		} else {
			throw std::string("Robotomy failed for " + getFormName() + "'s target: " + _target);
		}
	} catch (const std::exception& e) {
		throw ;
	}
	sleep(1);
}
