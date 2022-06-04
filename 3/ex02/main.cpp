#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap nameless;
	ClapTrap kkaneko("kkaneko");
	FragTrap enemy("enemy");

	kkaneko.attack("enemy");
	enemy.attack("kkaneko");
	enemy.highFivesGuys();

	return (0);
}
