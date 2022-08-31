#include <iostream>
#include "FragTrap.hpp"

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
	FragTrap nameless;
	FragTrap assigned;
	FragTrap named("name");
	FragTrap clone(named);

	assigned = named;
	std::cout << nameless << std::endl;
	std::cout << named << std::endl;
	std::cout << clone << std::endl;
	std::cout << assigned << std::endl;
}

static void funcTest(void)
{
	FragTrap dummy("dummy");
	FragTrap player("player");

	while (dummy.isFine())
	{
		std::cout << player << std::endl;
		std::cout << dummy << std::endl;
		player.attack("dummy");
		dummy.takeDamage(15);
		dummy.beRepaired(5);
		dummy.highFivesGuys();
	}
	// When dummy is fainted
	dummy.attack("player");
	dummy.beRepaired(100);
	dummy.highFivesGuys();
}
