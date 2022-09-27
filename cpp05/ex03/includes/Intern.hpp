/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/24 14:30:18 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/27 09:42:10 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>

#include <AForm.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 
#define CYAN    "\033[36m"
#define BOLD    "\x1B[1m"

class Intern {// : public AForm {
	public:
		Intern(void);// Default (no args) constructor
		Intern(const Intern& src);// Overloaded Copy constructor
		Intern& operator=(const Intern& rhs);// Copy assignment operator
		virtual ~Intern(void);// Destructor

		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
