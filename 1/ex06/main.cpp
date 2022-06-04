#include <iostream>
#include "Karen.hpp"

int main( int ac, char **av )
{
	const std::string arg_err = "Argument error";
	Karen karen;

	if (ac != 2)
	{
		std::cerr << arg_err << std::endl;
		return (1);
	}
	karen.complain(av[1]);
	return (0);
}
