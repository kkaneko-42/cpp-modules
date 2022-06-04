#include <iostream>
#include <string>
#include "Zombie.hpp"

void Zombie::announce( void )
{
	const std::string kScreamMsg = "BraiiiiiiinnnzzzZ...";

	std::cout << this->getName() + ": " << kScreamMsg << std::endl;
}

std::string Zombie::getName( void )
{
	return (this->name_);
}

void Zombie::setName( std::string name )
{
	this->name_ = name;
}

Zombie::~Zombie( void )
{
	const std::string kDiedMsg = "dead.";

	std::cout << this->getName() + ": " << kDiedMsg << std::endl;
}
