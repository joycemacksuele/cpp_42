/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/27 14:58:26 by jfreitas      ########   odam.nl         */
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

/* Abstract class:
 *
 * A class is abstract if it has at least one pure virtual method.
 * = 0 means derived classes must provide an implementation, not that the base
 * class can not provide an implementation.
 *
 * An Abstract class can't be instanciated
 *
 * If we do not override the pure virtual function in derived class,
 * then derived class also becomes abstract class.
 */

/* Access specifiers:
 *
 * public: members are accessible from outside the class
 * private: members cannot be accessed (or viewed) from outside the class
 * protected: members cannot be accessed from outside the class, however, they
 *            can be accessed in inherited classes.
 */
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
		bool				requirementsToExecute(const Bureaucrat& executor);
		virtual void		execute(const Bureaucrat& executor) = 0;

		void	throwError(const unsigned int& gradeToSign, const unsigned int& gradeToExecute);

		class GradeTooHighException : public std::exception {
			private:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				virtual const char* what(void) const throw();
		};

	protected:
		//const unsigned int&	getLowestGradeToSign() const;
		//const unsigned int&	getLowestGradeToExecute() const;
		const unsigned int&	getHighestGrade() const;
		//void setLowestGradeToSign(const unsigned int& lowestGradeToSign);
		//void setLowestGradeToExecute(const unsigned int& lowestGradeToExecute);

		// setters
		void	setHighestGrade(const unsigned int& highestGrade);
		void	setGradeToSign(const unsigned int& gradeToSign);
		void	setGradeToExecute(const unsigned int& gradeToExecute);
		void	setFormName(const std::string& formName);

	private:
		//unsigned int				_lowestGradeToSign;
		//unsigned int				_lowestGradeToExecute;
		unsigned int				_highestGrade;
		std::string					_formName;
		bool						_isSigned;
		bool						_isExecuted;
		unsigned int				_gradeToSign;
		unsigned int				_gradeToExecute;

};

std::ostream& operator<<(std::ostream& outputStream, const AForm& rhs);

#endif
