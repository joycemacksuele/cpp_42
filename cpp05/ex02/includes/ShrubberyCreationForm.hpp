/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/13 17:37:50 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

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

class ShrubberyCreationForm : private Form{
	public:
		ShrubberyCreationForm(void);// Default (no args) constructor
		ShrubberyCreationForm(const std::string& ShrubberyCreationFormName const);// Overloaded constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& src);// Overloaded Copy constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);// Copy assignment operator
		virtual ~ShrubberyCreationForm(void);// Destructor

		// getters
		const std::string&	getShrubberyCreationFormName() const;
		bool				getIsSigned() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string			_ShrubberyCreationFormName;
		bool						_isSigned;
		unsigned int				_gradeToSign;
		unsigned int				_gradeToExecute;

		void	throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute);
		// setters
		void	setGradeToSign(const unsigned int& gradeToSign);
		void	setGradeToExecute(const unsigned int& gradeToExecute);

		class GradeTooHighException : public std::exception {
			private:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm& rhs);

#endif
