#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->setType(type);
}

Weapon::Weapon( void )
{
	std::cout << "in!!" << std::endl;
}

const std::string &Weapon::getType( void )
{
	return (this->type);
}

void Weapon::setType( std::string type )
{
	this->type = type;
}
