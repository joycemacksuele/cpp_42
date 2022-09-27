/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/24 14:31:27 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 
#define CYAN    "\033[36m"
#define BOLD    "\x1B[1m"

class AForm;
class Bureaucrat {
	public:
		Bureaucrat(void);// Default (no args) constructor
		Bureaucrat(const std::string& name, const unsigned int& grade);// Overloaded constructor
		Bureaucrat(const Bureaucrat& src);// Overloaded Copy constructor
		Bureaucrat& operator=(const Bureaucrat& rhs);// Copy assignment operator
		virtual ~Bureaucrat(void);// Destructor

		// getters
		const std::string&	getName() const;
		const unsigned int&	getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(const bool& isSigned, const std::string& formName, const unsigned int& gradeToSignForm) const;
        void	executeForm(const AForm& form);

	private:
		static const unsigned int	_lowestGrade = 150;
		static const unsigned int	_highestGrade = 1;
		const std::string			_name;
		unsigned int				_grade;//1 (highest possible grade) to 150 (lowest possible grade).

		void	throwError(const unsigned int& grade);
		// setters
		void	setGrade(const unsigned int& grade);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& rhs);

#endif
