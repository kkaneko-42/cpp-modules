#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span
{
	public:
        typedef unsigned int size_type;

        Span( unsigned int n = 0 ); // wraping default constructor
		Span( const Span &src );
		virtual ~Span( void );

		Span &operator =( const Span &rhs );

		unsigned int getSize( void ) const;

		void addNumber( int number );

        template <class InputIt>
        void addNumber( InputIt start, InputIt end ) {
            if (current_size_ + (end - start) > max_size_) {
                throw std::logic_error("Span assignation: size not enought");
            }
            
            for (InputIt it = start; it != end; ++it) {
                values_[current_size_] = *it;
                ++current_size_;
            }
        }

		unsigned int shortestSpan( void ) const;
		unsigned int longestSpan( void ) const;
	
	private:
        const unsigned int max_size_;
		unsigned int current_size_;
		int *values_;
};

#endif //SPAN_HPP
