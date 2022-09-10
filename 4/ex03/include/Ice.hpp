#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( const Ice &src );
		virtual ~Ice( void );

		AMateria *clone(void) const;
		void use(ICharacter &target);

		static const std::string kIceType;
};

#endif //ICE_HPP
