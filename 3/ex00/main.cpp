#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap nameless;
	ClapTrap kkaneko("kkaneko");
	ClapTrap enemy("enemy");
	ClapTrap clone(kkaneko);

	kkaneko.attack("enemy");
	enemy.attack("kkaneko");
	kkaneko.beRepaired(10);
	kkaneko.attack("enemy");

	return (0);
}
