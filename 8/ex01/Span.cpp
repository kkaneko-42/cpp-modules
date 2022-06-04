#include <iostream>
#include <string>
#include <limits>
#include "Span.hpp"

static void copy_array( int *dst, int *src, unsigned int size );
static int my_abs_int( int a );

Span::Span( void ) : now_size_(0), size_(0)
{
	const std::string kMsg = "Span default constructor called";

	this->values_ = new int[0];
	std::cout << kMsg << std::endl;
}

Span::Span( const Span &src )
{
	const std::string kMsg = "Span copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

Span::Span( unsigned int n ) : now_size_(0), size_(n)
{
	this->values_ = new int[n];
}

Span::~Span( void )
{
	const std::string kMsg = "Span destructor called";

	delete[] this->values_;
	std::cout << kMsg << std::endl;
}

Span &Span::operator =( const Span &rhs )
{
	const std::string kMsg = "Span assignation oparator called";

	if (this != &rhs)
	{
		this->now_size_ = rhs.now_size_;
		this->size_ = rhs.size_;
		this->values_ = new int[this->size_];
		copy_array(this->values_, rhs.values_, this->size_);
	}

	return (*this);
}

static void copy_array( int *dst, int *src, unsigned int size )
{
	for (unsigned int i = 0; i < size; ++i)
		dst[i] = src[i];
}

unsigned int Span::getSize( void ) const
{
	return (this->size_);
}

void Span::addNumber( int number )
{
	if (now_size_ == size_)
		throw std::logic_error("Span is already full.");
	else
	{
		values_[now_size_] = number;
		++now_size_;
	}
}

unsigned int Span::shortestSpan( void ) const
{
	unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
	unsigned int span;

	if (size_ < 2)
		throw std::logic_error("Array is too short to calculate span.");
	else
	{
		for (unsigned int i = 1; i < size_; ++i)
		{
			span = my_abs_int(values_[i - 1] - values_[i]);
			if (span < shortest_span)
				shortest_span = span;
		}
	}
	return (shortest_span);
}

unsigned int Span::longestSpan( void ) const
{
	unsigned int longest_span = std::numeric_limits<unsigned int>::min();
	unsigned int span;

	if (size_ < 2)
		throw std::logic_error("Array is too short to calculate span.");
	else
	{
		for (unsigned int i = 1; i < size_; ++i)
		{
			span = my_abs_int(values_[i - 1] - values_[i]);
			if (span > longest_span)
				longest_span = span;
		}
	}
	return (longest_span);
}

static int my_abs_int( int a )
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
