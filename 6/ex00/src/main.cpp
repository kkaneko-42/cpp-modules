#include <iostream>
#include <string>
#include <cstring>
#include "ft_convert.hpp"

static void print_usage(void);

int main( int ac, char **av )
{
	if (ac != 2)
	{
		print_usage();
		return (1);
	}

	std::string str = av[1];
	std::cout << "char: " << ToChar(str) << std::endl;
	std::cout << "int: " << ToInt(str) << std::endl;
	std::cout << "float: " << ToFloat(str) << std::endl;
	std::cout << "double: " << ToDouble(str) << std::endl;
	return (0);
}

static void print_usage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
