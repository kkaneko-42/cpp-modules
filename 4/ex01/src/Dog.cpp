#include <iostream>
#include "Dog.hpp"

Dog::Dog( void )
{
	const std::string kMsg = "Dog default constructor called";

	this->type_ = "Dog";
	this->brain_ = new Brain();
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

	delete this->brain_;
	std::cout << kMsg << std::endl;
}

Dog &Dog::operator =( const Dog &rhs )
{
	const std::string kMsg = "Dog assignation operator called";

	if (this != &rhs)
	{
		this->type_ = rhs.type_;
		if (rhs.brain_ == NULL)
			this->brain_ = NULL;
		else
			this->brain_ = new Brain(*(rhs.brain_));
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const
{
	const std::string sound = "bow wow!";

	std::cout << this->type_ + ": " << sound << std::endl;
}
