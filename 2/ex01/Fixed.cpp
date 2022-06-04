#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

static int floatToRaw( const float num );

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

Fixed::Fixed( const int init )
{
	const std::string msg = "Int constructor called";

	std::cout << msg << std::endl;
	this->setRawBits(init << Fixed::nb_fract_bits_);
}

Fixed::Fixed( const float init )
{
	const std::string msg = "Float constructor called";

	std::cout << msg << std::endl;
	this->setRawBits(floatToRaw(init));
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

std::ostream &operator <<( std::ostream &out, const Fixed &src )
{
	out << src.toFloat();
	return (out);
}

int Fixed::getRawBits( void ) const
{
	return (this->raw_bits_);
}

void Fixed::setRawBits( int const raw )
{
	this->raw_bits_ = raw;
}

float Fixed::toFloat( void ) const
{
	float res;
	
	res = ((float)(this->getRawBits()) / (float)(1 << 8));

	return (res);
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> Fixed::nb_fract_bits_);
}

static int floatToRaw( const float num )
{
	int res;

	res = (int)(roundf(num * (1 << 8)));
	return (res);
}
