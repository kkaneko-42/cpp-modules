#include <iostream>
#include <string>
#include <cstdlib>
#include "Data.hpp"
#define USAGE "./a.out <Number tested>"

int main( int ac, char **av )
{
	Data data;
	uintptr_t res = serialize(&data);

	if (ac != 2)
	{
		std::cerr << USAGE << std::endl;
		return (1);
	}

	data.value = atoi(av[1]);
	std::cout << "Data's addr: " << std::hex << &data << std::endl;
	std::cout << "Serialize res: " << std::hex << res << std::endl;
	std::cout << "Deserialize->value: " << std::dec << deserialize(res)->value << std::endl;
	return (0);
}
