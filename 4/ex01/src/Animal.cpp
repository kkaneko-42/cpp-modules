#include <iostream>
#include "Animal.hpp"

Animal::Animal( void )
{
	const std::string kMsg = "Animal default constructor called";

	this->type_ = "";
	std::cout << kMsg << std::endl;
}

Animal::Animal( const Animal &src )
{
	const std::string kMsg = "Animal copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

Animal::Animal( const std::string &type )
{
	const std::string kMsg = "Animal naming constructor called";

	this->type_ = type;
	std::cout << kMsg << std::endl;
}

Animal::~Animal( void )
{
	const std::string kMsg = "Animal destructor called";

	std::cout << kMsg << std::endl;
}

Animal &Animal::operator =( const Animal &rhs )
{
	const std::string kMsg = "Animal assignation operator called";

	if (this != &rhs)
	{
		this->type_ = rhs.type_;
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void Animal::makeSound( void ) const
{
	const std::string sound = "Ahhhhh";

	std::cout << this->type_ + ": " << sound << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->type_);
}
