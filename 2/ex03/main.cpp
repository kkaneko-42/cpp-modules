#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Point.hpp"

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point );
static float ft_stof( char *str );

int main( int ac, char **av )
{
	if (ac != 9)
		return (1);

	Point a(ft_stof(av[1]), ft_stof(av[2]));
	Point b(ft_stof(av[3]), ft_stof(av[4]));
	Point c(ft_stof(av[5]), ft_stof(av[6]));
	Point p(ft_stof(av[7]), ft_stof(av[8]));
	std::string res;

	if (bsp(a, b, c, p))
		res = "inside";
	else
		res = "outside";
	std::cout << res << std::endl;
	return (0);
}

static float ft_stof( char *str )
{
	std::stringstream ss;
	float res;

	ss << str;
	ss >> res;
	return (res);
}
