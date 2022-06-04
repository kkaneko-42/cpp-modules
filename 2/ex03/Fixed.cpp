#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

static int floatToRaw( const float num );

Fixed::Fixed( void ) : raw_bits_(0)
{
}

Fixed::Fixed( const Fixed &src )
{
	*this = src;
}

Fixed::Fixed( const int init )
{
	this->setRawBits(init << Fixed::nb_fract_bits_);
}

Fixed::Fixed( const float init )
{
	this->setRawBits(floatToRaw(init));
}

Fixed::~Fixed( void )
{
}

Fixed &Fixed::operator =( const Fixed &src )
{
	this->raw_bits_ = src.getRawBits();
	return (*this);
}

bool Fixed::operator ==( const Fixed &rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator !=( const Fixed &rhs ) const
{
	return (!(*this == rhs));
}

bool Fixed::operator <=( const Fixed &rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator >=( const Fixed &rhs ) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator <( const Fixed &rhs ) const
{
	return (!(*this >= rhs));
}

bool Fixed::operator >( const Fixed &rhs) const
{
	return (!(*this <= rhs));
}

Fixed Fixed::operator +( const Fixed &rhs ) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator -( const Fixed &rhs ) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator *( const Fixed &rhs ) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator /( const Fixed &rhs ) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator ++( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator ++( int )
{
	Fixed res = *this;

	++(*this);
	return (res);
}

Fixed &Fixed::operator --( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator --( int )
{
	Fixed res = *this;

	--(*this);
	return (res);
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

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int floatToRaw( const float num )
{
	int res;

	res = (int)(roundf(num * (1 << 8)));
	return (res);
}
