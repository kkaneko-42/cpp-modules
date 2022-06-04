#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &src );
		Fixed( const int init );
		Fixed( const float init );
		~Fixed( void );
		Fixed &operator =( const Fixed &src );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int raw_bits_;
		static const int nb_fract_bits_ = 8;
};

std::ostream &operator <<( std::ostream &out, const Fixed &src );

#endif //FIXED_HPP
