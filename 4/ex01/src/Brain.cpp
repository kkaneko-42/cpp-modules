#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
	const std::string kMsg = "Brain default constructor called";

	InitIdeas();
	std::cout << kMsg << std::endl;
}

Brain::Brain( const Brain &src )
{
	const std::string kMsg = "Brain copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

Brain::~Brain( void )
{
	const std::string kMsg = "Brain destructor called";

	std::cout << kMsg << std::endl;
}

Brain &Brain::operator =( const Brain &rhs )
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; ++i)
		{
			this->ideas_[i] = rhs.ideas_[i];
		}
	}
	return (*this);
}

void Brain::setIdea( const std::string &idea, size_t index )
{
	const std::string kOutofIndexMsg = "Brain::setIdea: index is out of range";
	
	if (index > 100)
		std::cout << kOutofIndexMsg << std::endl;
	else
		this->ideas_[index] = idea;
}

std::string Brain::getIdea( size_t index ) const
{
	const std::string kOutofIndexMsg = "Brain::getIdea: index is out of range";

	if (index > 100)
	{
		std::cout << kOutofIndexMsg << std::endl;
		return ("");
	}
	else
		return (this->ideas_[index]);
}

void Brain::InitIdeas( void )
{
	const std::string kDefaultIdea = "";

	for (size_t i = 0; i < 100; ++i)
	{
		this->ideas_[i] = kDefaultIdea;
	}
}
