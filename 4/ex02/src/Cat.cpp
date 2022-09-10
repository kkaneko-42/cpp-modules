#include <iostream>
#include "Cat.hpp"

Cat::Cat( void )
{
	const std::string kMsg = "Cat default constructor called";

	this->type = "Cat";
	this->brain_ = new Brain();
	std::cout << kMsg << std::endl;
}

Cat::Cat( const Cat &src ) : AAnimal()
{
	const std::string kMsg = "Cat copy constructor called";

	this->brain_ = NULL;
	*this = src;
	std::cout << kMsg << std::endl;
}

Cat::~Cat( void )
{
	const std::string kMsg = "Cat destructor called";

	delete this->brain_;
	std::cout << kMsg << std::endl;
}

Cat &Cat::operator =( const Cat &rhs )
{
	const std::string kMsg = "Cat assignation operator called";

	this->type = rhs.type;
	if (rhs.brain_ == NULL)
		this->brain_ = NULL;
	else
	{
		delete this->brain_;
		this->brain_ = new Brain(*(rhs.brain_));
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

void Cat::makeSound( void ) const
{
	const std::string sound = "Mew mew";

	std::cout << this->type + ": " << sound << std::endl;
}
