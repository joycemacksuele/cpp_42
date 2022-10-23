/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:35:56 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/23 11:14:02 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

/* ########################################################################## */

// Default constructor
ExplicitConversion::ExplicitConversion(void)
	: _verbose(false), _hasSign(0), _wrongInput(false), _literal(""), _char(""), _int(""), _float(""), _double("") {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET << " Default constructor called" << std::endl;
	}
	return ;
}

// Overloaded constructor
ExplicitConversion::ExplicitConversion(const std::string& literal, const bool verbose)
	: _verbose(verbose), _hasSign(0), _wrongInput(false), _literal(literal), _char(""), _int(""), _float(""), _double("") {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET << " Overloaded constructor called" << std::endl;
	}
	return ;
}

// Copy constructor
ExplicitConversion::ExplicitConversion(const ExplicitConversion &src) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET << " Copy constructor called" << std::endl;
	}
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ExplicitConversion& ExplicitConversion::operator=(const ExplicitConversion& rhs) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET << " Copy assignment operator called" << std::endl;
	}
	if (this != &rhs) {
		this->_literal = rhs.getLiteral();
		this->_char = rhs.getChar();
		this->_int = rhs.getInt();
		this->_float = rhs.getFloat();
		this->_double = rhs.getDouble();
	}
	return *this;
}

// Destructor
ExplicitConversion::~ExplicitConversion(void) {
	if (isVerbose()) {
		std::cout << RED << "ExplicitConversion" << RESET << " Destructor called" << std::endl << std::endl;
	}
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& ExplicitConversion::getLiteral() const {
	return this->_literal;
}

//void ExplicitConversion::setLiteral(const std::string& literal) {
//	this->_literal = literal;
//}

const std::string& ExplicitConversion::getChar() const {
	return this->_char;
}

//void ExplicitConversion::setChar(const char& charLiteral) {
//	this->_char = charLiteral;
//}

const std::string& ExplicitConversion::getInt() const {
	return this->_int;
}

//void ExplicitConversion::setInt(const int& intLiteral) {
//	this->_int = intLiteral;
//}

const std::string& ExplicitConversion::getFloat() const {
	return this->_float;
}

//void ExplicitConversion::setFloat(const float& floatLiteral) {
//	this->_float = floatLiteral;
//}

const std::string& ExplicitConversion::getDouble() const {
	return this->_double;
}

//void ExplicitConversion::setDouble(const double& doubleLiteral) {
//	this->_double = doubleLiteral;
//}

bool ExplicitConversion::isVerbose() const {
	return _verbose;
}

//void ExplicitConversion::setVerbose(const bool& verbose) {
//	this->_verbose = verbose;
//}

void ExplicitConversion::hasSign(const int& sign) {
	this->_hasSign = sign;
}

void ExplicitConversion::wrongInput(const bool& input) {
	this->_wrongInput = input;
}

bool ExplicitConversion::inputIsWrong() const {
	return _wrongInput;;
}


/* ########################################################################## */
//Class member methods
void ExplicitConversion::assignLiteral() {
	try {
		_char = isChar();
	} catch (const std::exception& e) {
		_char = e.what();
	}

	try {
		checkInput();
	} catch (const std::exception& e) {

		_int = e.what();
		_float = e.what();
		_double = e.what();

		return ;
	}

	try {
		_int = isInt();
	} catch (const std::exception& e) {
		_int = e.what();
	}

	try {
		_float = isFloat();
	} catch (const std::exception& e) {
		_float = e.what();
	}

	try {
		_double = isDouble();
	} catch (const std::exception& e) {
		_double = e.what();
	}
}

const std::string ExplicitConversion::isChar() {
	if (_literal.size() == 1) {
		//std::cout << RED << std::isdigit(static_cast<unsigned char>(_literal.at(0))) << RESET <<std::endl;
		// if the input (as a char) is not from 0 to 9 (digits) and they are
		// ascii printable then it can be converted to a char
		if (std::isprint(static_cast<unsigned char>(_literal.at(0))) != 0 &&
				std::isdigit(static_cast<unsigned char>(_literal.at(0))) == 0) {
			return std::to_string(_literal[0]);
		} else {
			// if the input (as a char) is from 0 to 9, its not displayable
			if (std::isdigit(static_cast<unsigned char>(_literal.at(0))) != 0) {
				throw ExplicitConversion::NotDisplayableException();
			} else {
				throw ExplicitConversion::ImpossibleException();
			}
		}
	} else {
		throw ExplicitConversion::ImpossibleException();
	}
}

const std::string ExplicitConversion::isInt() {
	try {
		if (_literal.back() != 'f' && std::strcmp(_literal.c_str(), "nan") != 0
			&& _literal.find('.') == std::string::npos) {
			return std::to_string(std::stoi(_literal));
		}
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
		//std::cout << "not INT - exception- CONTINUE" << std::endl;
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::isFloat() {
	std::ostringstream floatString;
	floatString.setf(std::ios::fixed);
	floatString.precision(1);
	try {
		std::cout << YELLOW << _literal << RESET << std::endl;
		if (/*_literal.back() == 'f' &&*/checkInput()) {
			floatString << std::stof(_literal);
			return floatString.str();
		}
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
		//std::cout << "UNKNOWN FLOAT" << std::endl;
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::isDouble() {
	std::ostringstream doubleString;
	doubleString.setf(std::ios::fixed);
	doubleString.precision(1);
	try {
		doubleString << std::stod(_literal);
		return doubleString.str();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
		//std::cout << "UNKNOWN DOUBLE" << std::endl;
	}
}

bool ExplicitConversion::checkInput() {
	unsigned long literal_size = _literal.size();

	if (_literal.front() == '-' || _literal.front() == '+') {
		hasSign(1);
	}
	// checking if literal with no sign equals any pseudo literal
	if (_literal.compare(_hasSign, literal_size, "inff") == 0 ||
			_literal.compare(_hasSign, literal_size,"nanf") == 0 ||
			_literal.compare(_hasSign, literal_size, "inf") == 0 ||
			_literal.compare(_hasSign, literal_size, "nan") == 0) {
		return true;// it is pseudo float or double
	}

	for (unsigned long i = 0; i < literal_size; i++) {
		if (std::isdigit(static_cast<unsigned char>(_literal[i]))) {//needed?
			continue ;// it is an int (number/digit)
		} else if (i != literal_size - 1 && _literal[i] != '.') {
			// if index is not at the end of string but is also not a '.'
			wrongInput(true);
			throw ExplicitConversion::ImpossibleException();
		}
		// if index is at the end of string and it finds a 'f'
		if (i == literal_size -1 && _literal.back() != 'f') {// todo != f?? or  ==
			break ;// it is not a float
		}

	}
	return true;
}


/* ########################################################################## */
// Exception handling
const char* ExplicitConversion::NotDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ExplicitConversion::ImpossibleException::what() const throw() {
	return "Impossible";
}

/*const std::string& ExplicitConversion::charException() const {

}*/

/* ########################################################################## */
/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const ExplicitConversion& rhs) {


	outputStream << "char: " << rhs.getChar() << std::endl;

	if (rhs.inputIsWrong()) {
		outputStream << "int: " << rhs.getInt() << std::endl;
		outputStream << "float: " << rhs.getFloat() << std::endl;
		outputStream << "double: " << rhs.getDouble() << std::endl;
		return outputStream;
	}
	outputStream << "int: " << rhs.getInt() << std::endl;
	outputStream << "float: " << rhs.getFloat() << 'f' << std::endl;
	outputStream << "double: " << rhs.getDouble() << std::endl;

	return outputStream;
}

/* C-style Casting:         (data_type)expression;
 * Function-style Casting:  data_type(expression);
 *
 * Type Conversion operators: example_cast<new_type>(expression)
 *
 * static_cast
 *   - Performs all conversions allowed implicitly.
 *   - Explicitly call a single-argument constructor or a conversion operator.
 *   - Convert to rvalue references.
 *   - Convert from void* to any pointer type.
 *   - Convert any type to void, evaluating and discarding the value.
 *   - Convert integers, floating-point values and enum types to enum types.
 *   - Convert enum class values into integers or floating-point values.
 *   - Obs: No checks are performed during runtime to guarantee that the object
 *   being converted is in fact a full object of the destination type. Therefore,
 *   it is up to the programmer to ensure that the conversion is safe.
 *
 * dynamic_cast
 *   - Can only be used with pointers and references to classes (or with void*).
 *   - Can also downcast (convert from pointer-to-base to pointer-to-derived)
 *   polymorphic classes (those with virtual members) if -and only if- the
 *   pointed object is a valid complete object of the target type.
 *   - Can also perform the other implicit casts allowed on pointers: casting
 *   null pointers between pointers types (even between unrelated classes),
 *   and casting any pointer of any type to a void* pointer.
 *   - Obs: When it cannot cast a pointer because it is not a complete object
 *   of the required class it returns a null pointer to indicate the failure.
 *
 * const_cast
 *   - This type of casting manipulates the constness of the object pointed by
 *   a pointer, either to be set or to be removed.
 *   - Obs: Removing the constness of a pointed object to actually write to it
 *   causes undefined behavior.
 * reinterpret_cast
 *   - Converts any pointer type to other pointer type, even of unrelated classes.
 *     Neither the content pointed nor the pointer type itself is checked.
 *   - It can also cast pointers to or from integer types.
 */
