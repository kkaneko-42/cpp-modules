#include <iostream>
#include "ClapTrap.hpp"

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
	ClapTrap nameless;
	ClapTrap assigned;
	ClapTrap named("name");
	ClapTrap clone(named);

	assigned = named;
	std::cout << nameless << std::endl;
	std::cout << named << std::endl;
	std::cout << clone << std::endl;
	std::cout << assigned << std::endl;
}

static void funcTest(void)
{
	ClapTrap dummy("dummy");
	ClapTrap player("player");

	while (dummy.isFine())
	{
		std::cout << player << std::endl;
		std::cout << dummy << std::endl;
		player.attack("dummy");
		dummy.takeDamage(5);
		dummy.beRepaired(2);
	}
	// When dummy is fainted
	dummy.attack("player");
	dummy.beRepaired(100);
}
