#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure &src );
		virtual ~Cure( void );

		AMateria *clone(void) const;
		void use(ICharacter &target);

		static const std::string kCureType;
};

#endif //CURE_HPP
