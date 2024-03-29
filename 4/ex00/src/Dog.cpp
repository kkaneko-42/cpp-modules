#include <iostream>
#include "Dog.hpp"

Dog::Dog( void )
{
	const std::string kMsg = "Dog default constructor called";

	this->type = "Dog";
	std::cout << kMsg << std::endl;
}

Dog::Dog( const Dog &src ) : Animal(src)
{
	const std::string kMsg = "Dog copy constructor called";

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
		this->type_ = rhs.type_;
	std::cout << kMsg << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const
{
	const std::string kSound = "bow wow!";

	std::cout << this->type_ + ": " << kSound << std::endl;
}
