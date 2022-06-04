#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria( void );
		AMateria( const AMateria &src );
		AMateria( std::string const &type );
		virtual ~AMateria( void ) = 0;

		AMateria &operator =( const AMateria &rhs );

		std::string const &getType( void ) const;
		
		virtual AMateria *clone( void ) const = 0;
		virtual void use( ICharacter &target );
};

#endif //AMATERIA_HPP
