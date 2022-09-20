#include <iostream>
#include <string>
#include <cstring>
#include "Converter.hpp"

static void printUsage(void);

int main( int ac, char **av )
{
	if (ac != 2)
	{
		printUsage();
		return (1);
	}

	std::string str = av[1];
	// std::cout << "char: " << ToChar(str) << std::endl;
	// std::cout << "int: " << ToInt(str) << std::endl;
	std::cout << "float: " << Converter::toFloat(str) << std::endl;
	// std::cout << "double: " << ToDouble(str) << std::endl;
	return (0);
}

static void printUsage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
