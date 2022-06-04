#include <iostream>
#include <cstring>
#include "iter.hpp"

static void ToUpper(char &c);

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	iter<char>(av[1], strlen(av[1]), ToUpper);
	std::cout << av[1] << std::endl;
	return (0);
}

static void ToUpper(char &c)
{
	if ('a' <= c && c <= 'z')
		c += 'A' - 'a';
}
