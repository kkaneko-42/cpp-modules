#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>

class Span
{
	public:
		Span( void );
		Span( const Span &src );
		Span( unsigned int n );
		virtual ~Span( void );

		Span &operator =( const Span &rhs );

		unsigned int getSize( void ) const;

		void addNumber( int number );
		unsigned int shortestSpan( void ) const;
		unsigned int longestSpan( void ) const;
	
	private:
		unsigned int now_size_;
		unsigned int size_;
		int *values_;
};

#endif //SPAN_HPP
