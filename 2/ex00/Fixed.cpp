#include <iostream>
#include <string>
#include "Fixed.hpp"

Fixed::Fixed( void ) : raw_bits_(0)
{
	const std::string msg = "Default constructor called";

	std::cout << msg << std::endl;
}

Fixed::Fixed( const Fixed &src )
{
	const std::string msg = "Copy constructor called";

	std::cout << msg << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	const std::string msg = "Destructor called";

	std::cout << msg << std::endl;
}

Fixed &Fixed::operator =( const Fixed &src )
{
	const std::string msg = "Copy assignment operator called";

	std::cout << msg << std::endl;
	this->raw_bits_ = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	const std::string msg = "getRawBits member function called";

	std::cout << msg << std::endl;
	return (this->raw_bits_);
}

void Fixed::setRawBits( int const raw )
{
	this->raw_bits_ = raw;
}
