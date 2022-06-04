#include <iostream>
#include "Karen.hpp"

static void test_karen( std::string arg );

int main( int ac, char **av )
{
	test_karen("DEBUG");
	test_karen("INFO");
	test_karen("WARNING");
	test_karen("ERROR");
	test_karen("HOGEHOGE");
	if (ac >= 2)
		test_karen(av[1]);
	return (0);
}

static void test_karen( std::string arg )
{
	Karen karen;

	std::cout << "======= Test: " << arg << " =======" << std::endl;
	karen.complain(arg);
}
