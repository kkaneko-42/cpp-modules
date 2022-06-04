#include <iostream>
#include "Karen.hpp"

static size_t search_level_index( std::string level, size_t nb_levels );

std::string Karen::levels_[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Karen::Karen( void )
{
	this->member_funcs_[0] = &Karen::debug;
	this->member_funcs_[1] = &Karen::info;
	this->member_funcs_[2] = &Karen::warning;
	this->member_funcs_[3] = &Karen::error;
}

void Karen::complain( std::string level )
{
	const size_t nb_levels = 4;
	const std::string error_msg = "[ Probably complaining about insignificant problems ]";
	size_t level_idx = search_level_index(level, nb_levels);

	if (level_idx == nb_levels)
		std::cout << error_msg << std::endl;
	else
	{
		for (size_t i = level_idx; i < nb_levels; ++i)
		{
			std::cout << "[ " << Karen::levels_[i] << " ]" << std::endl;
			(this->*member_funcs_[i])();
			std::cout << std::endl;
		}
	}
}

static size_t search_level_index( std::string level , size_t nb_levels )
{
	size_t level_idx = 0;

	while (level_idx < nb_levels)
	{
		if (level == Karen::levels_[level_idx])
			break;
		++level_idx;
	}
	return (level_idx);
}

void Karen::debug( void )
{
	const std::string msg = \
"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n\
I really do!";

	std::cout << msg << std::endl;
}

void Karen::info( void )
{
	const std::string msg = \
"I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger!\n\
If you did, I wouldn’t be asking for more!";

	std::cout << msg << std::endl;
}

void Karen::warning( void )
{
	const std::string msg = \
"I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.";

	std::cout << msg << std::endl;
}

void Karen::error( void )
{
	const std::string msg = \
"This is unacceptable, I want to speak to the manager now.";

	std::cout << msg << std::endl;
}
