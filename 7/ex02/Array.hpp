#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <stdexcept>

template <class T>
class Array
{
	public:
		Array( void ): size_(0), values_(NULL)
		{ }

		Array( unsigned int n ): size_(static_cast<std::size_t>(n))
		{
			values_ = new T[n];
			for (std::size_t i = 0; i < this->size_; ++i)
				this->values_[i] = T();
		}

		Array( const Array &src )
		{
			size_ = 0;
			values_ = NULL;
			*this = src;
		}

		virtual ~Array( void )
		{
			delete[] this->values_;
			this->values_ = NULL;
		}

		Array &operator =( const Array &rhs )
		{
			if (this != &rhs)
			{
				delete[] this->values_;
				this->values_ = new T[rhs.size()];
				this->size_ = rhs.size();
				for (std::size_t i = 0; i < this->size_; ++i)
					this->values_[i] = rhs.values_[i];
			}

			return (*this);
		}

		T &operator []( std::size_t n )
		{
			if (n >= this->size_)
				throw std::logic_error("Array: Index is out of range");
			else
				return (this->values_[n]);
		}

		std::size_t size( void ) const
		{
			return (this->size_);
		}

	private:
		T *values_;
		std::size_t size_;
};

#endif //ARRAY_HPP
