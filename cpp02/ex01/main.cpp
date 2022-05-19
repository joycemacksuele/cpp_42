#include <cmath>
# include <iostream>

class Fixed
{
public:
	Fixed( void ): _fixed_point_value(0) {
			std::cout << "Default constructor called" << std::endl;
		return;
	}

	Fixed( const int value ) {
			std::cout << "Constant integer constructor called" << std::endl;
		this->_fixed_point_value = value << this->_number_of_fractional_bits;
		return;
	}

	Fixed( const float value ) {
		int power = pow(2, this->_number_of_fractional_bits);
			std::cout << "Constant float constructor called" << std::endl;
		this->_fixed_point_value = roundf(value * power);
		return;
	}

	Fixed( const Fixed &src ) {
			std::cout << "Copy constructor called" << std::endl;
		*this = src;
		return;
	}

	~Fixed( void ) {
			std::cout << "Destructor called" << std::endl;
		return;
	}

	Fixed	&operator=( const Fixed &rhs ) {
			std::cout << "Assignement operator called" << std::endl;
		if (this != &rhs)
			this->_fixed_point_value = rhs._fixed_point_value;
		return *this;
	}

	int		toInt( void ) const {
		return (this->_fixed_point_value >> this->_number_of_fractional_bits);
	}

	float	toFloat( void ) const {
		std::cout << std::endl << "_fixed_point_value =  " << this->_fixed_point_value << std::endl;
		int		power = pow(2, this->_number_of_fractional_bits);
		float	result = (float)this->_fixed_point_value / power;
		return (result);
	}

	int		getRawBits( void ) const {
		return (this->_fixed_point_value);
	}

	void	setRawBits( const int raw ) {
		this->_fixed_point_value = raw;
	}

private:
	int					_fixed_point_value;
	static const int	_number_of_fractional_bits = 8;
};

std::ostream	&operator<<( std::ostream &ostream, const Fixed &myClass ) {
	ostream << myClass.toFloat();
	return (ostream);
}

///////////////////////////////

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 13.5f );
	Fixed const d( b );
	Fixed const e( 20.75f );
	a = Fixed( 1234.4375f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;

	std::cout << "rawbits of a =  " << a.getRawBits() << std::endl;


	return (0);
}
