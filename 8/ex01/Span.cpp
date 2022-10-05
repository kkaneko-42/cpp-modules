#include <iostream>
#include <string>
#include <limits>
#include "Span.hpp"

static int my_abs_int( int a );

Span::Span( unsigned int n ) : max_size_(n), current_size_(0)
{
    values_ = new int[n];
    for (unsigned int i = 0; i < n; ++i) {
        values_[i] = 0;
    }
}

Span::Span( const Span &src ) : max_size_(src.max_size_)
{
	*this = src;
}

Span::~Span( void )
{
    delete values_;
}

Span &Span::operator =( const Span &rhs )
{
	if (this != &rhs)
	{
        if (max_size_ < rhs.current_size_) {
            throw std::logic_error("Span assignation: size not enought");
        }
        for (unsigned int i = 0; i < rhs.current_size_; ++i) {
            values_[i] = rhs.values_[i];
        }
	}

	return (*this);
}

unsigned int Span::getSize( void ) const
{
	return (this->current_size_);
}

void Span::addNumber( int number )
{
	if (current_size_ == max_size_)
		throw std::logic_error("Span is already full.");
	else
	{
		values_[current_size_] = number;
		++current_size_;
	}
}

unsigned int Span::shortestSpan( void ) const
{
	unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
	unsigned int span;

	if (current_size_ < 2) {
        throw std::logic_error("Array is too short to calculate span.");
    } else {
		for (unsigned int i = 0; i < current_size_; ++i)
		{
            for (unsigned int j = i + 1; j < current_size_; ++j) {
                span = my_abs_int(values_[i] - values_[j]);
                if (span < shortest_span) {
                    shortest_span = span;
                }
            }
		}
	}

	return (shortest_span);
}

unsigned int Span::longestSpan( void ) const
{
	unsigned int longest_span = std::numeric_limits<unsigned int>::min();
	unsigned int span;

	if (current_size_ < 2) {
        throw std::logic_error("Array is too short to calculate span.");
    } else {
		for (unsigned int i = 0; i < current_size_; ++i)
		{
            for (unsigned int j = i + 1; j < current_size_; ++j) {
                span = my_abs_int(values_[i] - values_[j]);
                if (span > longest_span) {
                    longest_span = span;
                }
            }
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
