#include <iostream>
#include "ScavTrap.hpp"

static void occfTest(void);
static void funcTest(void);

int main( void )
{
	occfTest();
	funcTest();
	return (0);
}

static void occfTest(void)
{
	ScavTrap nameless;
	ScavTrap assigned;
	ScavTrap named("name");
	ScavTrap clone(named);

	assigned = named;
	std::cout << nameless << std::endl;
	std::cout << named << std::endl;
	std::cout << clone << std::endl;
	std::cout << assigned << std::endl;
}

static void funcTest(void)
{
	ScavTrap dummy("dummy");
	ScavTrap player("player");

	while (dummy.isFine())
	{
		std::cout << player << std::endl;
		std::cout << dummy << std::endl;
		player.attack("dummy");
		dummy.takeDamage(15);
		dummy.beRepaired(5);
		dummy.guardGate();
	}
	// When dummy is fainted
	dummy.attack("player");
	dummy.beRepaired(100);
	dummy.guardGate();
}
