#include <iostream>
#include <string>
#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{}

Point::Point( const Fixed &x, const Fixed &y ) : x(x), y(y)
{
	// std::cout << "x:" << this->getX() << std::endl;
	// std::cout << "y:" << this->getY() << std::endl;
}

Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y))
{}

Point::Point( const Point &src )
{
	*this = src;
}

Point::~Point( void )
{}

Point &Point::operator =( const Point &src )
{
	Fixed thisX = this->getX();
	Fixed thisY = this->getY();

	thisX = src.getX();
	thisY = src.getY();
	return (*this);
}

Point Point::operator -( const Point &rhs ) const
{
	Point res(this->getX() - rhs.getX(), this->getY() - rhs.getY());

	return (res);
}

Fixed &Point::getX( void ) const
{
	return (const_cast<Fixed&>(this->x));
}

Fixed &Point::getY( void ) const
{
	return (const_cast<Fixed&>(this->y));
}
