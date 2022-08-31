#include <iostream>
#include "DiamondTrap.hpp"

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
	DiamondTrap nameless;
	DiamondTrap assigned;
	DiamondTrap named("name");
	DiamondTrap clone(named);

	assigned = named;
	std::cout << nameless << std::endl;
	std::cout << named << std::endl;
	std::cout << clone << std::endl;
	std::cout << assigned << std::endl;
}

static void funcTest(void)
{
	DiamondTrap dummy("dummy");
	DiamondTrap player("player");

	dummy.whoAmI();
	while (dummy.ScavTrap::isFine())
	{
		std::cout << player << std::endl;
		std::cout << dummy << std::endl;
		player.attack("dummy");
		dummy.ScavTrap::takeDamage(15);
		dummy.ScavTrap::beRepaired(5);
		dummy.guardGate();
		dummy.highFivesGuys();
	}
	// When dummy is fainted
	dummy.attack("player");
	dummy.ScavTrap::beRepaired(100);
	dummy.guardGate();
	dummy.highFivesGuys();
}
