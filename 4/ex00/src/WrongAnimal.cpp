#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	const std::string kMsg = "WrongAnimal default constructor called";

	this->type = "";
	std::cout << kMsg << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	const std::string kMsg = "WrongAnimal copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

WrongAnimal::WrongAnimal( const std::string &type )
{
	const std::string kMsg = "WrongAnimal naming constructor called";

	this->type = type;
	std::cout << kMsg << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	const std::string kMsg = "WrongAnimal destructor called";

	std::cout << kMsg << std::endl;
}

WrongAnimal &WrongAnimal::operator =( const WrongAnimal &rhs )
{
	const std::string kMsg = "WrongAnimal assignation operator called";

	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	const std::string sound = "I am a wrong animal";

	std::cout << this->type + ": " << sound << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}
