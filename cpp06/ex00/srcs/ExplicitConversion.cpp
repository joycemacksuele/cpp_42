/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:35:56 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/23 17:48:44 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

/* ########################################################################## */

// Default constructor
ExplicitConversion::ExplicitConversion(void)
	: _verbose(false),
	_hasSign(0),
	_wrongInput(false),
	_literal(""),
	_char(""), _int(""), _float(""), _double("") {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET << " Default constructor called" << std::endl;
	}
	return ;
}

// Overloaded constructor
ExplicitConversion::ExplicitConversion(const std::string& literal, const bool verbose)
	: _verbose(verbose),
	_hasSign(0),
	_wrongInput(false),
	_literal(literal),
	_char(""), _int(""), _float(""), _double("") {
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

void ExplicitConversion::wrongInput(const bool& input) {// todo delete
	this->_wrongInput = input;
}

bool ExplicitConversion::inputIsWrong() const {
	return _wrongInput;
}


/* ########################################################################## */
//Class member methods
void ExplicitConversion::assignLiteral() {
	std::cout << RED << "literal = " << _literal << RESET << std::endl;
	_literalType = assignLiteralToTypes();
	std::cout << RED << "literal type = " << _literalType << RESET << std::endl;
	try {
		_char = toChar();
	} catch (const std::exception& e) {
		_char = e.what();
	}

	/*try {
		checkInput();
	} catch (const std::exception& e) {
		_int = e.what();
		_float = e.what();
		_double = e.what();
		return ;
	}*/

	try {
		_int = toInt();
	} catch (const std::exception& e) {
		_int = e.what();
	}

	try {
		_float = toFloat();
	} catch (const std::exception& e) {
		_float = e.what();
	}

	try {
		_double = toDouble();
	} catch (const std::exception& e) {
		_double = e.what();
	}
}

const std::string ExplicitConversion::toChar() {
	switch(_literalType) {
		case CHAR:
			return std::string(1, _literal.at(0));
		case INT:
			try {
				// if possible, the int literal can be coverted to its printable ascii element
				int literalAsInt = stoi(_literal);
				if (std::isprint(static_cast<unsigned char>(literalAsInt)) != 0) {
					std::ostringstream intString;
					intString << static_cast<char>(literalAsInt);
					return intString.str();
				} else {
					throw ExplicitConversion::NotDisplayableException();
				}
			} catch (...) {
				throw ExplicitConversion::NotDisplayableException();
			}
		case FLOAT:
			try {
				// if possible, the float literal can be coverted to int and then
				// to its printable ascii element
				int literalAsInt = stoi(_literal);
				if (std::isprint(static_cast<unsigned char>(literalAsInt)) != 0) {
					std::ostringstream intString;
					intString << static_cast<char>(literalAsInt);
					return intString.str();
				} else {
					throw ExplicitConversion::NotDisplayableException();
				}
			} catch (...) {
				throw ExplicitConversion::NotDisplayableException();
			}
		case DOUBLE:
			throw ExplicitConversion::ImpossibleException();
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
	}

			// if the input (as a char) is from 0 to 9, its not displayable
		//throw ExplicitConversion::NotDisplayableException();
		//throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toInt() {
	switch(_literalType) {
		case CHAR:
			// if the literal input is a char, it can print its ascii number:o
			// int(_literal.at(0))
			return std::to_string(static_cast<int>(_literal.at(0)));
		case INT:
			try {
				return std::to_string(std::stoi(_literal));
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case FLOAT:
			try {
				return std::to_string(std::stoi(_literal));
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case DOUBLE:
			try {
				std::ostringstream doubleString;
				doubleString.setf(std::ios::fixed);
				doubleString.precision(1);
				doubleString << std::stod(_literal);
				return doubleString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toFloat() {
	switch(_literalType) {
		case CHAR:
			// if the literal input is a char, it can print its ascii number:o
			// int(_literal.at(0))
			return std::to_string(static_cast<int>(_literal.at(0)));
		case INT:
			try {
				return std::to_string(std::stoi(_literal));
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case FLOAT:
			try {
				std::ostringstream floatString;
				floatString.setf(std::ios::fixed);
				floatString.precision(1);
				floatString << std::stof(_literal) << 'f';
				return floatString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case DOUBLE:
			try {
				std::ostringstream doubleString;
				doubleString.setf(std::ios::fixed);
				doubleString.precision(1);
				doubleString << std::stod(_literal);
				return doubleString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toDouble() {
	std::ostringstream doubleString;
	doubleString.setf(std::ios::fixed);
	doubleString.precision(1);
	try {
		doubleString << std::stod(_literal);
		return doubleString.str();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
}

ExplicitConversion::ConvertTo ExplicitConversion::assignLiteralToTypes() {
	unsigned long literal_size = _literal.size();

	if (_literal.front() == '-' || _literal.front() == '+') {
		hasSign(1);
	}
	// checking if literal with no sign equals any pseudo literal:
	if (_literal.compare(_hasSign, literal_size, "inff") == 0 ||
			_literal.compare(_hasSign, literal_size,"nanf") == 0) {
		return FLOAT;
	}
	if (_literal.compare(_hasSign, literal_size, "inf") == 0 ||
			_literal.compare(_hasSign, literal_size, "nan") == 0) {
		return DOUBLE;
	}

	// if literal has 1 digit, this digit is printable and not a number/digit:
	if (literal_size == 1 &&
			std::isprint(static_cast<unsigned char>(_literal.at(0))) != 0 &&
			std::isdigit(static_cast<unsigned char>(_literal.at(0))) == 0) {
		return CHAR;
	}

	unsigned long i = _hasSign;
	for (i = 0; i < literal_size; i++) {
		// check if the index is not a digit or '.':
		if (std::isdigit(static_cast<unsigned char>(_literal.at(i))) == 0 &&
				_literal[i] != '.') {
			break ;
		}
	}

	std::cout << YELLOW << "i: " << i << " | size: " << literal_size << RESET << std::endl;
	// if literal is at the end of the string by now and does not end with 'f':
	if (i == literal_size && _literal.back() != 'f') {
		// if literali has NO '.':
		if (_literal.find('.') == std::string::npos) {
			return INT;
		} else if (_literal.find('.') != std::string::npos) {// TODO find a better way???
			// if it did not return INT, it means it does not end with 'f' and has a '.':
			return DOUBLE;
		}
	}
	// if literal is at its penultimate index and it ends with 'f':
	if (i == (literal_size - 1) && _literal.back() == 'f') {
		return FLOAT;
	}
		return UNKNOWN;
			//wrongInput(true);
			//throw ExplicitConversion::ImpossibleException();
}

/* ########################################################################## */
// Exception handling
const char* ExplicitConversion::NotDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ExplicitConversion::ImpossibleException::what() const throw() {
	return "Impossible";
}

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
	outputStream << "float: " << rhs.getFloat() << std::endl;
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
