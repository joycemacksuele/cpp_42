/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/12 18:26:39 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>

#include <Bureaucrat.hpp>

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
class Form {
	public:
		Form(void);// Default (no args) constructor
		Form(const std::string& name, const unsigned int& grade);// Overloaded constructor
		Form(const Form& src);// Overloaded Copy constructor
		Form& operator=(const Form& rhs);// Copy assignment operator
		virtual ~Form(void);// Destructor

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what(void) const throw();
		};

		// getters and setters
		const std::string&	getName() const;
		bool				getIsSigned() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;
		//void				setGrade(const unsigned int& grade);

		void				beSigned(const Bureaucrat& bureaucrat);// will access the signForm() method form Buraucrat
		//void				incrementGrade();
		//void				decrementGrade();

	private:
		const std::string	_name;
		bool				isSigned = false;
		//1 (highest possible grade) to 150 (lowest possible grade).
		const unsigned int	gradeToSign;
		const unsigned int	gradeToExecute;

};

std::ostream& operator<<(std::ostream& outputStream, const Form& rhs);

#endif
