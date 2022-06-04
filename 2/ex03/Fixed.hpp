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
		bool operator ==( const Fixed &rhs ) const;
		bool operator !=( const Fixed &rhs ) const;
		bool operator <=( const Fixed &rhs ) const;
		bool operator >=( const Fixed &rhs ) const;
		bool operator >( const Fixed &rhs ) const;
		bool operator <( const Fixed &rhs ) const;
		Fixed operator +( const Fixed &rhs ) const;
		Fixed operator -( const Fixed &rhs ) const;
		Fixed operator *( const Fixed &rhs ) const;
		Fixed operator /( const Fixed &rhs ) const;
		Fixed &operator ++( void );
		Fixed operator ++( int n );
		Fixed &operator --( void );
		Fixed operator --( int n );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );

	private:
		int raw_bits_;
		static const int nb_fract_bits_ = 8;
};

std::ostream &operator <<( std::ostream &out, const Fixed &src );

#endif //FIXED_HPP
