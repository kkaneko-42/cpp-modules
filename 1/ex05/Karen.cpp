#include <iostream>
#include "Karen.hpp"

Karen::Karen( void )
{
	this->levels_[0] = "DEBUG";
	this->levels_[1] = "INFO";
	this->levels_[2] = "WARNING";
	this->levels_[3] = "ERROR";

	this->member_funcs_[0] = &Karen::debug;
	this->member_funcs_[1] = &Karen::info;
	this->member_funcs_[2] = &Karen::warning;
	this->member_funcs_[3] = &Karen::error;
}

void Karen::complain( std::string level )
{
	const size_t nb_levels = 4;
	const std::string error_msg = level + ": No such level.";
	size_t level_idx;

	level_idx = 0;
	while (level_idx < nb_levels)
	{
		if (level == this->levels_[level_idx])
			break ;
		++level_idx;
	}
	if (level_idx == nb_levels)
		std::cout << error_msg << std::endl;
	else
		(this->*member_funcs_[level_idx])();
}

void Karen::debug( void )
{
	const std::string msg = \
"I love having extra bacon \
for my 7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!";

	std::cout << msg << std::endl;
}

void Karen::info( void )
{
	const std::string msg = \
"I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!";

	std::cout << msg << std::endl;
}

void Karen::warning( void )
{
	const std::string msg = \
"I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month.";

	std::cout << msg << std::endl;
}

void Karen::error( void )
{
	const std::string msg = \
	"This is unacceptable! I want to speak to the manager now.";

	std::cout << msg << std::endl;
}
