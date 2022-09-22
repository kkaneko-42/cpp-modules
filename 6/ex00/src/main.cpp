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
    std::cout << "=== Literal: \"" << str << "\" ===" << std::endl;
    std::cout << "type: " << Converter::typeOf(str) << std::endl;
    std::cout << "convert: " << Converter::convert(str) << std::endl;

	std::cout << "as char: ";
    try {
        std::cout << Converter::toChar(str) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << "as int: ";
    try {
        std::cout << Converter::toInt(str) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << "as float: ";
    try {
        std::cout << Converter::toFloat(str) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << "as double: ";
    try {
        std::cout << Converter::toDouble(str) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return (0);
}

static void printUsage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
