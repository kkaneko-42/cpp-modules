#include <iostream>
#include <string>
#include <cstdlib>

void exit_with_error(const std::string msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}
