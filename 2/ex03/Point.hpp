#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( const Fixed &x, const Fixed &y );
		Point( const float x, const float y );
		Point( const Point &src );
		~Point( void );

		Point &operator =( const Point &src );
		Point operator -( const Point &rhs ) const;

		Fixed &getX( void ) const;
		Fixed &getY( void ) const;

	private:
		const Fixed x;
		const Fixed y;
};

#endif
