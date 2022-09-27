/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/27 09:47:52 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

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

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);// Default (no args) constructor
		PresidentialPardonForm(const std::string& target);// Overloaded constructor
		PresidentialPardonForm(const PresidentialPardonForm& src);// Overloaded Copy constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);// Copy assignment operator
		virtual ~PresidentialPardonForm(void);// Destructor

		virtual void		execute(const Bureaucrat& executor);

	private:
		std::string _target;
};

#endif
