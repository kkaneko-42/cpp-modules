#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &src );
		~Fixed( void );
		Fixed &operator =( const Fixed &src );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int raw_bits_;
		static const int nb_fract_bits_ = 8;
};

#endif //FIXED_HPP
