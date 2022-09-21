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
	std::cout << "char: " << Converter::toChar(str) << std::endl;
	std::cout << "int: " << Converter::toInt(str) << std::endl;
	std::cout << "float: " << Converter::toFloat(str) << std::endl;
	std::cout << "double: " << Converter::toDouble(str) << std::endl;
	return (0);
}

static void printUsage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
