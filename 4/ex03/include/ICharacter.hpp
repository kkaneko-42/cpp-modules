#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter
{
	public:
		ICharacter( void );
		ICharacter( const ICharacter &src );
		virtual ~ICharacter( void );

		ICharacter &operator =( const ICharacter &rhs );
};

#endif //ICHARACTER_HPP
