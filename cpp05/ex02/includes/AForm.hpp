/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/28 18:11:10 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <fstream>

#include <Bureaucrat.hpp>

// A class is abstract if it has at least one pure virtual function.
// If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
class AForm {
	public:
		AForm(void);// Default (no args) constructor
		AForm(const std::string& FormName, const unsigned int& gradeToSign, const unsigned int& gradeToExecute);// Overloaded constructor
		AForm(const AForm& src);// Overloaded Copy constructor
		AForm& operator=(const AForm& rhs);// Copy assignment operator
		virtual ~AForm(void);// Destructor

		// getters
		const std::string&	getFormName() const;
		bool				getIsSigned() const;
		bool				getIsExecuted() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);
        virtual void		execute(const Bureaucrat& executor) const = 0;
		bool				requirementsToExecute(const Bureaucrat& executor) const;
        // virtual method (pure method)
		// = 0 means it can't be implemented here so the class can't be instanciated
		// but should be implemented/overriten by the child class(es)

		void	throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute);

		class GradeTooHighException : public std::exception {
			private:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				virtual const char* what(void) const throw();
		};

	private:
		static const unsigned int	_lowestGrade = 150;
		static const unsigned int	_highestGrade = 1;
		const std::string			_formName;
		bool						_isSigned;
		bool						_isExecuted;
		unsigned int				_gradeToSign;
		unsigned int				_gradeToExecute;


		// setters
		void	setGradeToSign(const unsigned int& gradeToSign);
		void	setGradeToExecute(const unsigned int& gradeToExecute);
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& rhs);

#endif
