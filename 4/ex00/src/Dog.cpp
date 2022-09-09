#include <iostream>
#include "Dog.hpp"

Dog::Dog( void )
{
	const std::string kMsg = "Dog default constructor called";

	this->type = "Dog";
	std::cout << kMsg << std::endl;
}

Dog::Dog( const Dog &src ) : Animal()
{
	const std::string kMsg = "Dog copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

Dog::~Dog( void )
{
	const std::string kMsg = "Dog destructor called";

	std::cout << kMsg << std::endl;
}

Dog &Dog::operator =( const Dog &rhs )
{
	const std::string kMsg = "Dog assignation operator called";

	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const
{
	const std::string sound = "bow wow!";

	std::cout << this->type + ": " << sound << std::endl;
}
