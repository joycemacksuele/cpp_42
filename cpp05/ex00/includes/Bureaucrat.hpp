/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/12 17:29:16 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\x1B[1m"

/*
 * Access specifiers:
 * public: members are accessible from outside the class
 * private: members cannot be accessed (or viewed) from outside the class
 * protected: members cannot be accessed from outside the class, however, they
 *            can be accessed in inherited classes.
 */
class Bureaucrat {
	public:
		Bureaucrat(void);// Default (no args) constructor
		Bureaucrat(const std::string& name, const unsigned int& grade);// Overloaded constructor
		Bureaucrat(const Bureaucrat& src);// Overloaded Copy constructor
		Bureaucrat& operator=(const Bureaucrat& rhs);// Copy assignment operator
		virtual ~Bureaucrat(void);// Destructor

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what(void) const throw();
		};

		// getters and setters
		const std::string&	getName() const;
		const unsigned int&	getGrade() const;
		void				setGrade(const unsigned int& grade);

		void				incrementGrade();
		void				decrementGrade();

	private:
		const std::string	_name;
		unsigned int		_grade;//1 (highest possible grade) to 150 (lowest possible grade).
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& rhs);

#endif
