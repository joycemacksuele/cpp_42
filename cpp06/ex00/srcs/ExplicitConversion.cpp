/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ExplicitConversion.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 11:35:56 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/05 19:46:53 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ExplicitConversion.hpp>

/* ########################################################################## */

// Default constructor
ExplicitConversion::ExplicitConversion(void)
	:_literal(""), _char(""), _int(""), _float(""), _double(""),
	_literalType(UNKNOWN), _hasSign(0), _verbose(false) {
	if (isVerbose()) {
		std::cout << GREEN << "ExplicitConversion" << RESET;
		std::cout << " Default constructor called" << std::endl;
	}
	_outString.setf(std::ios::fixed);
	return ;
}

// Overloaded constructor
ExplicitConversion::ExplicitConversion(const std::string& literal, const bool verbose)
	: _literal(literal), _char(""), _int(""), _float(""), _double(""),
	_literalType(UNKNOWN), _hasSign(0), _verbose(verbose) {
	if (isVerbose()) {
		std::cout << GREEN << std::endl << "ExplicitConversion" << RESET;
		std::cout << " Overloaded constructor called" << std::endl;
	}
	_outString.setf(std::ios::fixed);
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
	// Here I am not chekcing the limits of the numbers since the stoi/f/d will
	// trhow exceptions if it is "out of range".
	unsigned long literal_size = _literal.size();// size_t is unsigned long

	// setting the presition of the float and double
	_outString.precision(checkPrecision());

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

	// if literal has 1 digit that is printable and not a number:
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
			// if it has nore than 1 '.':
			if (++hasMoreDots > 1) {
				return UNKNOWN;
			}
		}
	}

	// if literal is at the end of the string by now and does not end with 'f':
	if (i == literal_size && _literal.back() != 'f') {
		return _literal.find('.') == std::string::npos ? INT : DOUBLE;
	}

	// if literal is at its penultimate index and it ends with 'f':
	if (i == (literal_size - 1) && _literal.back() == 'f') {
		// Example of first converting the literal string to its type (this
		// conversion does not put an 'f' at the end). Later on (the exmaple
		// is on toInt() case FLOAT) explicitlity converting from the input type
		// (float) to one of the data types (in this example, int).
		// _literalAsFloat = stof(_literal);// private member (float _literalAsFloat;)
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
	std::cout << YELLOW << "literal type =  "  << _literalType << std::endl;
	std::cout << "literal = " << _literal << RESET << std::endl;
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

/* -------------------------------------------------------------------------- */

const std::string ExplicitConversion::toChar() {
	_outString.str("");
	try {
		switch (_literalType) {
			case CHAR:
				_outString << '\'' << _literal.at(0) << '\'';
				return _outString.str();
				//return std::string(1, _literal.at(0));
			case INT:
				return numberToChar();
			case FLOAT:
				return numberToChar();
			case DOUBLE:
				return numberToChar();
			case UNKNOWN:
				throw ExplicitConversion::ImpossibleException();
		}
	} catch (ExplicitConversion::NotDisplayableException const& ex) {
		throw ExplicitConversion::NotDisplayableException();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::numberToChar() {
	// if possible, the int, floar or double literal can be coverted
	// to int and then to its printable ascii element
	int literalAsInt = std::stoi(_literal);
	if (literalAsInt < 32 || literalAsInt == 127) {
		throw ExplicitConversion::NotDisplayableException();
	}
	if (std::isprint(literalAsInt) != 0) {
		_outString << '\'' << static_cast<char>(literalAsInt) << '\'';
		return _outString.str();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toInt() {
	_outString.str("");
	try {
		switch (_literalType) {
			case INT:
				return std::to_string(std::stoi(_literal));
			case CHAR:
			// if the literal input is a char, it can print its ascii number
			// int(_literal.at(0))
				return std::to_string(static_cast<int>(_literal.at(0)));
			case FLOAT:
				// example of getting the input value already converted from
				// string to its data type, and now explicitily casted to the
				// type requested on the method (int since the method is toInd())
				//return std::to_string(static_cast<int>(_literalAsFloat));
				return std::to_string(std::stoi(_literal));
			case DOUBLE:
				return std::to_string(std::stoi(_literal));
			case UNKNOWN:
				throw ExplicitConversion::NotANumber();
		}
	} catch (std::out_of_range const& ex) {
		throw ExplicitConversion::Overflow();
	} catch (ExplicitConversion::NotANumber const& ex) {
		throw ExplicitConversion::NotANumber();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toFloat() {
	_outString.str("");
	try {
		switch (_literalType) {
			case FLOAT:
				_outString << std::stof(_literal) << 'f';
				return _outString.str();
			case CHAR: {
			// if the literal input is a char, it can print2147483647 its ascii number:
			// int(_literal.at(0))
				int literalAsInt = static_cast<int>(_literal.at(0));
				_outString << std::stof(std::to_string(literalAsInt)) << 'f';
				return _outString.str();
			}
			case INT:
				// A 4-byte float uses 23 bits to store the mantissa and 9 to
				// store the sign and exponent. This means that storing the
				// largest 32-bit integers (2147483648) cannot be done
				// completely accurately.
				// https://stackoverflow.com/questions/23420783/convert-int-max-to-float-and-then-back-to-integer
				// calculator: https://baseconvert.com/ieee-754-floating-point
				_outString << std::stof(_literal) << 'f';
				return _outString.str();
			case DOUBLE:
				_outString << std::stof(_literal) << 'f';
				return _outString.str();
			case UNKNOWN:
				throw ExplicitConversion::NotANumber();
		}
	} catch (std::out_of_range const& ex) {
		throw ExplicitConversion::Overflow();
	} catch (ExplicitConversion::NotANumber const& ex) {
		throw ExplicitConversion::NotANumber();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();
}

const std::string ExplicitConversion::toDouble() {
	_outString.str("");;
	try {
		switch (_literalType) {
			case DOUBLE:
				_outString << std::stod(_literal);
				return _outString.str();
			case CHAR: {
				// if the literal input is a char, it can print its ascii number:
				// int(_literal.at(0))
				int literalAsInt = static_cast<int>(_literal.at(0));
				_outString << std::stod(std::to_string(literalAsInt));
				return _outString.str();
			}
			case INT:
				_outString << std::stod(_literal);
				return _outString.str();
			case FLOAT:
				_outString << std::stod(_literal);
				return _outString.str();
			case UNKNOWN:
				throw ExplicitConversion::NotANumber();
		}
	} catch (std::out_of_range const& ex) {
		throw ExplicitConversion::Overflow();
	} catch (ExplicitConversion::NotANumber const& ex) {
		throw ExplicitConversion::NotANumber();
	} catch (...) {
		throw ExplicitConversion::ImpossibleException();
	}
	throw ExplicitConversion::ImpossibleException();

}

/* ########################################################################## */
// Exception handling
const char* ExplicitConversion::NotDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ExplicitConversion::ImpossibleException::what() const throw() {
	return "Impossible";
}

const char* ExplicitConversion::Overflow::what() const throw() {
	return "Overflowed";
}

const char* ExplicitConversion::NotANumber::what() const throw() {
	return "NaN";
}

/* ########################################################################## */
// Overloaded insertion («) operator
std::ostream& operator<<(std::ostream& outputStream, const ExplicitConversion& rhs) {
	if (!rhs.isVerbose()) {
		outputStream << std::endl;
	}
	outputStream << "char:   " << rhs.getChar() << std::endl;
	outputStream << "int:    " << rhs.getInt() << std::endl;
	outputStream << "float:  " << rhs.getFloat() << std::endl;
	outputStream << "double: " << rhs.getDouble() << std::endl;
	outputStream << std::endl;
	return outputStream;
}

/* ########################################################################## */
/* ########################################################################## */

/* About Type Conversion
 *
 * There are 2 types of type conversion in C++:
 *
 * 1. Implicit Conversion (also known as automatic conversion)
 * - Is done automatically done by the compiler, and data loss can happen
 * when data of a larger type is converted to data of a smaller type.
 *    E.g.:
 *        int num_int;
 *        double num_double = 9.99;
 *        num_int = num_double;
 *       // here num_int will be 9, so data loss occurred.
 *
 * 2. Explicit Conversion (also known as Type Casting)
 * - Is done manually and there are 3 major ways to do so in c++:
 *    1. C-style Type Casting:         (data_type)expression;
 *    2 .Function-style Type Casting:  data_type(expression);
 *    3. Type Conversion operators:    example_cast<new_type>(expression)
 *
 * ------
 *
 * There are 4 Type Conversion operators:
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
 *
 * reinterpret_cast
 *   - Converts any pointer type to other pointer type, even of unrelated classes.
 *     Neither the content pointed nor the pointer type itself is checked.
 *   - It can also cast pointers to or from integer types.
 *
 * Perks of C++ Type Comversion Operators:
 * 1. C++ style casts are checked by the compiler.
 * 2. Can be searched for easily, whereas it's really hard to search for c style casts.
 * 3. 4 different C++ style casts express the intent of the programmer more clearly.
 */
