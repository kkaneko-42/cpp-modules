#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *new_zombies = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		new_zombies[i].setName(name);
	}
	return (new_zombies);
}
