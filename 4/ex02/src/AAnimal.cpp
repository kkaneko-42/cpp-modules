#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	const std::string kMsg = "AAnimal default constructor called";

	this->type_ = "";
	std::cout << kMsg << std::endl;
}

AAnimal::AAnimal( const AAnimal &src )
{
	const std::string kMsg = "AAnimal copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

AAnimal::AAnimal( const std::string &type )
{
	const std::string kMsg = "AAnimal naming constructor called";

	this->type_ = type;
	std::cout << kMsg << std::endl;
}

AAnimal::~AAnimal( void )
{
	const std::string kMsg = "AAnimal destructor called";

	std::cout << kMsg << std::endl;
}

AAnimal &AAnimal::operator =( const AAnimal &rhs )
{
	const std::string kMsg = "AAnimal assignation operator called";

	if (this != &rhs)
	{
		this->type_ = rhs.type_;
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void AAnimal::makeSound( void ) const
{
	const std::string sound = "Ahhhhh";

	std::cout << this->type_ + ": " << sound << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return (this->type_);
}
