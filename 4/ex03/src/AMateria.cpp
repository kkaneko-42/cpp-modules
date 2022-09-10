#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : type_("")
{
}

AMateria::AMateria( const AMateria &src ) : type_(src.getType())
{
}

AMateria::AMateria( std::string const &type ) : type_(type)
{
}

AMateria::~AMateria( void )
{
}

AMateria &AMateria::operator =( const AMateria &rhs )
{
	(void)rhs;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (type_);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Use unknown materia to ";
	std::cout << target.getName() << std::endl;
}
