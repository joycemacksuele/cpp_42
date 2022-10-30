/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:35:56 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/30 14:57:02 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

/* ########################################################################## */

// Default constructor
ExplicitConversion::ExplicitConversion(void)
	:_literal(""), _char(""), _int(""), _float(""), _double(""),
	_hasSign(0), _precision(1), _verbose(false) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET;
		std::cout << " Default constructor called" << std::endl;
	}
	return ;
}

// Overloaded constructor
ExplicitConversion::ExplicitConversion(const std::string& literal, const bool verbose)
	: _literal(literal), _char(""), _int(""), _float(""), _double(""),
	_hasSign(0), _precision(1), _verbose(verbose) {
	if (isVerbose()) {
		std::cout << GREEN << std::endl << "ExplicitConversion" << RESET;
		std::cout << " Overloaded constructor called" << std::endl;
	}
	return ;
}

// Copy constructor
ExplicitConversion::ExplicitConversion(const ExplicitConversion &src) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET;
		std::cout << " Copy constructor called" << std::endl;
	}
	*this = src; // this will call the copy assignment operator
}

// Copy assignment operator
ExplicitConversion& ExplicitConversion::operator=(const ExplicitConversion& rhs) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET ;
		std::cout << " Copy assignment operator called" << std::endl;
	}
	if (this != &rhs) {
		this->_literal = rhs._literal;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
		this->_literalType = rhs._literalType;
		this->_hasSign = rhs._hasSign;
		this->_precision = rhs._precision;
		this->_verbose = rhs._verbose;
	}
	return *this;
}

// Destructor
ExplicitConversion::~ExplicitConversion(void) {
	if (isVerbose()) {
		std::cout << RED << "ExplicitConversion" << RESET;
		std::cout << " Destructor called" << std::endl << std::endl;
	}
	return ;
}

/* ########################################################################## */
// getters and setters

const std::string& ExplicitConversion::getChar() const {
	return this->_char;
}

const std::string& ExplicitConversion::getInt() const {
	return this->_int;
}

const std::string& ExplicitConversion::getFloat() const {
	return this->_float;
}

const std::string& ExplicitConversion::getDouble() const {
	return this->_double;
}

bool ExplicitConversion::isVerbose() const {
	return _verbose;
}

void ExplicitConversion::hasSign(const int& sign) {
	this->_hasSign = sign;
}

/* ########################################################################## */
//Class member methods

ExplicitConversion::ConvertTo ExplicitConversion::assignLiteralToTypes() {
	unsigned long literal_size = _literal.size();// size_t is unsigned long

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

	unsigned long i = 0;
	int hasMoreDots = 0;

	// Checking the _literal string starting after its sign:
	for (i = _hasSign; i < literal_size; i++) {
		// If the index is not a digit neither a '.', it will break to check
		// ater if its a float:
		if (std::isdigit(static_cast<unsigned char>(_literal.at(i))) == 0 &&
				_literal.at(i) != '.') {
			break ;
		}
		if (_literal.at(i) == '.') {
			if (++hasMoreDots > 1) {
				std::cout << CYAN << "hasMoreDots = " << hasMoreDots << RESET << std::endl;
				return UNKNOWN;
			}
		}
	}

	// if literal is at the end of the string by now and does not end with 'f':
	_precision = checkPrecision();
	//std::cout << YELLOW << "i: " << i << " | size: "  << literal_size << "| precision: " << _precision << RESET << std::endl;
	if (i == literal_size && _literal.back() != 'f') {
		return _literal.find('.') == std::string::npos ? INT : DOUBLE;
	}
	// if literal is at its penultimate index and it ends with 'f':
	if (i == (literal_size - 1) && _literal.back() == 'f') {
		return FLOAT;
	}
	return UNKNOWN;
}

int ExplicitConversion::checkPrecision() {
	unsigned long index = _literal.find(".");
	if (index == std::string::npos) {
		return 1;
	}
	unsigned long literalSize = _literal.size();
	if (_literal.back() == 'f') {
		literalSize--;
		std::cout << CYAN << "size without f: " << literalSize << std::endl;
	}
	int precision = 0;
	// starting from the next index in which '.' is
	while (index + 1 < literalSize) {
		index++;
		precision++;
	}
	return precision == 0 ? 1 : precision;
}

void ExplicitConversion::assignLiteral() {
	_literalType = assignLiteralToTypes();
	//std::cout << YELLOW << "literal type = " << _literalType << RESET << std::endl;
	try {
		_char = toChar();
	} catch (const std::exception& e) {
		_char = e.what();
	}

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
	std::ostringstream outString;
	outString.setf(std::ios::fixed);
	outString.precision(_precision);
	switch (_literalType) {
		case CHAR:
			return std::string(1, _literal.at(0));
		case INT:
			try {
				// if possible, the int literal can be coverted to its
				// printable ascii element
				int literalAsInt = std::stoi(_literal);
				if (std::isprint(static_cast<unsigned char>(literalAsInt)) != 0) {
					outString << static_cast<char>(literalAsInt);
					return outString.str();
				} else {
					break ;
				}
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case FLOAT:
			try {
				// if possible, the float literal can be coverted to int and then
				// to its printable ascii element
				int literalAsInt = std::stoi(_literal);// static_cast<int>(literalAsFloat);
				if (std::isprint(static_cast<unsigned char>(literalAsInt)) != 0) {
					outString << static_cast<char>(literalAsInt);
					return outString.str();
				} else {
					break ;
				}
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case DOUBLE:
			try {
				// if possible, the double literal can be coverted to int and
				// then to its printable ascii element
				int literalAsInt = std::stoi(_literal);
				if (std::isprint(static_cast<unsigned char>(literalAsInt)) != 0) {
					outString << static_cast<char>(literalAsInt);
					return outString.str();
				} else {
					break ;
				}
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
			break;
	}
	throw ExplicitConversion::NotDisplayableException();
}

const std::string ExplicitConversion::toInt() {
	switch (_literalType) {
		case CHAR:
			// if the literal input is a char, it can print its ascii number
			// int(_literal.at(0))
			return std::to_string(static_cast<int>(_literal.at(0)));
		case INT:
			return _literal;
		case FLOAT:
			try {
				//std::cout << CYAN << "literal as int= " << std::stoi(_literal) << RESET << std::endl;
				return std::to_string(std::stoi(_literal));
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case DOUBLE:
			try {
				return std::to_string(std::stoi(_literal));
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
			break;
	}
}

const std::string ExplicitConversion::toFloat() {
	std::ostringstream outString;
	outString.setf(std::ios::fixed);
	outString.precision(_precision);
	switch (_literalType) {
		case CHAR:
			// if the literal input is a char, it can print its ascii number:
			// int(_literal.at(0))
			try {
				int literalAsInt = static_cast<int>(_literal.at(0));
				outString << std::stof(std::to_string(literalAsInt)) << 'f';
				return outString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case INT:
			try {
				outString << std::stof(_literal) << 'f';
				return outString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case FLOAT:
			try {
				return _literal;
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case DOUBLE:
			try {
				outString << std::stof(_literal) << 'f';
				return outString.str();
			} catch (...) {
				throw ExplicitConversion::ImpossibleException();
			}
			break;
		case UNKNOWN:
			throw ExplicitConversion::ImpossibleException();
			break;
		//default:
	}
}

const std::string ExplicitConversion::toDouble() {
	std::ostringstream doubleString;
	doubleString.setf(std::ios::fixed);
	doubleString.precision(_precision);
	try {
		switch (_literalType) {
			case CHAR: {
				// if the literal input is a char, it can print its ascii number:
				// int(_literal.at(0))
				int literalAsInt = static_cast<int>(_literal.at(0));
				doubleString << std::stod(std::to_string(literalAsInt));
				return doubleString.str();
			}
			case INT:
				doubleString << std::stod(_literal);
				return doubleString.str();
			case FLOAT:
				doubleString << std::stod(_literal);
				return doubleString.str();
			case DOUBLE:
				return _literal;
			case UNKNOWN:
				throw ;
		}
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
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
	outputStream << std::endl;
	outputStream << "char: " << rhs.getChar() << std::endl;
	outputStream << "int: " << rhs.getInt() << std::endl;
	outputStream << "float: " << rhs.getFloat() << std::endl;
	outputStream << "double: " << rhs.getDouble() << std::endl;
	outputStream << std::endl;
	return outputStream;
}

/* ########################################################################## */
/* ########################################################################## */

/* About casting:
 *
 * C-style Casting:         (data_type)expression;
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
