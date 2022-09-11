#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	const std::string kMsg = "Cat default constructor called";

	this->type = "Cat";
	std::cout << kMsg << std::endl;
}

Cat::Cat( const Cat &src ) : Animal(src)
{
	const std::string kMsg = "Cat copy constructor called";

	std::cout << kMsg << std::endl;
}

Cat::~Cat( void )
{
	const std::string kMsg = "Cat destructor called";

	std::cout << kMsg << std::endl;
}

Cat &Cat::operator =( const Cat &rhs )
{
	const std::string kMsg = "Cat assignation operator called";

	this->type_ = rhs.type_;
	std::cout << kMsg << std::endl;
	return (*this);
}

void Cat::makeSound( void ) const
{
	const std::string sound = "Mew mew";

	std::cout << this->type + ": " << sound << std::endl;
}
