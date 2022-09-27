#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <stdexcept>

template <class T>
class Array
{
	public:
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* pointer;
        typedef unsigned int size_type;

		Array( void ): size_(0), values_(NULL)
		{ }

		Array( size_type n ): size_(n)
		{
			values_ = new T[n];
			for (size_type i = 0; i < this->size_; ++i)
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
                T* new_ptr = new T[rhs.size()]; // for safety if allocation failed
				delete[] this->values_;
				this->values_ = new_ptr;
				this->size_ = rhs.size();
				for (size_type i = 0; i < this->size_; ++i)
					this->values_[i] = rhs.values_[i];
			}

			return (*this);
		}

		reference operator []( size_type n )
		{
			if (n >= this->size_)
				throw std::out_of_range("Array: Index is out of range");
			else
				return (this->values_[n]);
		}

        const_reference operator []( size_type n ) const
		{
			if (n >= this->size_)
				throw std::out_of_range("Array: Index is out of range");
			else
				return (this->values_[n]);
		}

		size_type size( void ) const
		{
			return (this->size_);
		}

	private:
		pointer values_;
		size_type size_;
};

#endif //ARRAY_HPP
