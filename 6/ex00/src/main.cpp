#include <iostream>
#include "ft_convert.hpp"

static void print_usage(void);

int main( int ac, char **av )
{
	if (ac != 2)
	{
		print_usage();
		return (1);
	}

	std::cout << "char: " << ToChar(av[1]) << std::endl;
	std::cout << "int: " << ToInt(av[1]) << std::endl;
	std::cout << "float: " << ToFloat(av[1]) << std::endl;
	std::cout << "double: " << ToDouble(av[1]) << std::endl;
	return (0);
}

static void print_usage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
