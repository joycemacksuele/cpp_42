/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/28 18:12:39 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>

#include <AForm.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\x1B[1m"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);// Default (no args) constructor
		ShrubberyCreationForm(const std::string& target);// Overloaded constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& src);// Overloaded Copy constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);// Copy assignment operator
		virtual ~ShrubberyCreationForm(void);// Destructor

		void		execute(const Bureaucrat& executor) const;

	private:
		std::string _target;
};

std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm& rhs);

#endif
