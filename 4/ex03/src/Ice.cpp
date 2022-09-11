#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

const std::string Ice::kIceType = "ice";

Ice::Ice( void ) : AMateria(kIceType)
{

}

Ice::Ice( const Ice &src ) : AMateria(src.getType())
{
	*this = src;
}

Ice::~Ice( void )
{

}

AMateria *Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}
