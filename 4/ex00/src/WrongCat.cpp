#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	const std::string kMsg = "WrongCat default constructor called";

	this->type = "WrongCat";
	std::cout << kMsg << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal()
{
	const std::string kMsg = "WrongCat copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

WrongCat::~WrongCat( void )
{
	const std::string kMsg = "WrongCat destructor called";

	std::cout << kMsg << std::endl;
}

WrongCat &WrongCat::operator =( const WrongCat &rhs )
{
	const std::string kMsg = "WrongCat assignation operator called";

	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << kMsg << std::endl;
	return (*this);
}
