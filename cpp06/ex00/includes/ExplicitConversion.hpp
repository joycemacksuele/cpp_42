/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.hpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:37:43 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/23 11:06:26 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPLICITCONVERSION_HPP
# define EXPLICITCONVERSION_HPP

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
		ExplicitConversion(const std::string& literal, const bool verbose);// Overloaded constructor
		ExplicitConversion(const ExplicitConversion& src);// Overloaded Copy constructor
		ExplicitConversion& operator=(const ExplicitConversion& rhs);// Copy assignment operator
		virtual ~ExplicitConversion(void);// Destructor


		// getters and setters
		const std::string& getLiteral() const;
		void setLiteral(const std::string& literal);
		const std::string& getChar() const;
		//void				setChar(const char& charLiteral);
		const std::string& getInt() const;
		//void				setInt(const int& intLiteral);
		const std::string& getFloat() const;
		//void				setFloat(const float& floatLiteral);
		const std::string& getDouble() const;
		//void				setDouble(const double& doubleLiteral);
		//void				setVerbose(const bool& verbose);

		// class member methods
		void assignLiteral();
		bool isVerbose() const;
		void hasSign(const int& sign);
		void wrongInput(const bool& input);
		bool inputIsWrong() const;
		bool checkInput();

		const std::string isChar();
		const std::string isInt();
		const std::string isFloat();
		const std::string isDouble();


		// Exceptions
		class NotDisplayableException : public std::exception {
			virtual const char* what() const throw();
		};
		class ImpossibleException : public std::exception {
			virtual const char* what() const throw();
		};

		//const std::string& charException() const;

	private:
		bool _verbose;
		int _hasSign;
		bool _wrongInput;
		std::string _literal;
		std::string _char;
		std::string _int;
		std::string _float;
		std::string _double;
};

std::ostream& operator<<(std::ostream& outputStream, const ExplicitConversion& rhs);

#endif
