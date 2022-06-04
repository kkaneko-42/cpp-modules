#include <iostream>
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap nameless;
	ClapTrap kkaneko("kkaneko");
	ScavTrap enemy("enemy");

	kkaneko.attack("enemy");
	enemy.attack("kkaneko");
	enemy.guardGate();

	return (0);
}
