#include <iostream>
#include "Cure.hpp"

const std::string Cure::kCureType = "cure";

Cure::Cure( void ) : AMateria(kCureType)
{
}

Cure::Cure( const Cure &src ) : AMateria(src.getType())
{

}

Cure::~Cure( void )
{

}

AMateria *Cure::clone(void) const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s ";
	std::cout << "wounds *" << std::endl;
}
