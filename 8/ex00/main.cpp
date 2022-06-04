#include <iostream>
#include <string>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	int mirror[] = {1, 2, 3, 4, 5};
	std::vector<int> v;

	v.assign(&mirror[0], &mirror[5]);
	std::cout << *easyfind< std::vector<int> >(v, 5) << std::endl;
	std::cout << *easyfind< std::vector<int> >(v, 10) << std::endl;
	return (0);
}
