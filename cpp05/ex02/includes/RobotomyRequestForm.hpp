/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/02 10:59:03 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>

#include <AForm.hpp>
#include <Bureaucrat.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\x1B[1m"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);// Default (no args) constructor
		RobotomyRequestForm(const std::string& target);// Overloaded constructor
		RobotomyRequestForm(const RobotomyRequestForm& src);// Overloaded Copy constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);// Copy assignment operator
		virtual ~RobotomyRequestForm(void);// Destructor

		virtual void		execute(const Bureaucrat& executor);

	private:
		std::string _target;
};

std::ostream& operator<<(std::ostream& outputStream, const RobotomyRequestForm& rhs);

#endif
