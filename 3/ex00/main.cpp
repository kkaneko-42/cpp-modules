#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap nameless;
	ClapTrap kkaneko("kkaneko");
	ClapTrap enemy("enemy");
	ClapTrap clone(kkaneko);

	std::cout << kkaneko << std::endl;
	std::cout << enemy << std::endl;
	kkaneko.attack("enemy");
	enemy.takeDamage(2);
	enemy.attack("kkaneko");
	kkaneko.takeDamage(3);
	std::cout << kkaneko << std::endl;
	std::cout << enemy << std::endl;
	kkaneko.beRepaired(10);
	kkaneko.attack("enemy");

	return (0);
}
