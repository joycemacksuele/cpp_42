/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.hpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:37:43 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/01 13:55:39 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPLICITCONVERSION_HPP
# define EXPLICITCONVERSION_HPP

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

enum ConvertTo {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	UNKNOWN = 4
};// It is ordered from lower to higher data type

class ExplicitConversion {
	public:
		ExplicitConversion(void);// Default (no args) constructor
		ExplicitConversion(const std::string& name, const unsigned int& grade);// Overloaded constructor
		ExplicitConversion(const ExplicitConversion& src);// Overloaded Copy constructor
		ExplicitConversion& operator=(const ExplicitConversion& rhs);// Copy assignment operator
		virtual ~ExplicitConversion(void);// Destructor

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};

		// getters and setters
		const unsigned int&	getGrade() const;
		void				setGrade(const unsigned int& grade);


	private:
		const std::string	_name;
};

std::ostream& operator<<(std::ostream& outputStream, const ExplicitConversion& rhs);

#endif
