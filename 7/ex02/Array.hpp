#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <string>
#include <stdexcept>

template <class T>
class Array
{
	public:
		Array( void )
		{
			const std::string kMsg = "Arrat default constructor called";

			this->size_ = 0;
			this->values_ = new T[0];
			std::cout << kMsg << std::endl;
		}

		Array( const Array &src )
		{
			const std::string kMsg = "Array copy constructor called";

			this->values_ = new T[src.size()];
			*this = src;
			std::cout << kMsg << std::endl;
		}

		Array( unsigned int n )
		{
			this->size_ = static_cast<size_t>(n);
			this->values_ = new T[n];
			for (size_t i = 0; i < this->size_; ++i)
				this->values_[i] = 0;
		}

		virtual ~Array( void )
		{
			const std::string kMsg = "Array destructor called";

			delete[] this->values_;
			std::cout << kMsg << std::endl;
		}

		Array &operator =( const Array &rhs )
		{
			const std::string kMsg = "Array assignation operator called";

			this->size_ = rhs.size();
			for (size_t i = 0; i < this->size_; ++i)
				this->values_[i] = rhs.values_[i];

			return (*this);
		}

		T &operator []( size_t n )
		{
			if (n + 1 > this->size_)
				throw std::logic_error("Index is out of range");
			else
				return (this->values_[n]);
		}

		size_t size( void ) const
		{
			return (this->size_);
		}

	private:
		T *values_;
		size_t size_;
};

#endif //ARRAY_TPP
