#include <iostream>
#include <string>
#include "Zombie.hpp"

int main( int ac, char **av)
{
	if (ac != 2)
		return (0);

	std::string input(av[1]);
	Zombie *res;

	std::cout << "-----test randomChump------" << std::endl;
	randomChump(input);

	std::cout << "-----test newZombie------" << std::endl;
	res = newZombie(input);
	res->announce();
	delete res;

	return (0);
}
