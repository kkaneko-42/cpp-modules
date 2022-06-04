#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : name(name), weapon(NULL){}

void HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}

void HumanB::attack( void )
{
	const std::string attack_msg = " attacks with their ";
	std::string weapon_type;

	if (this->weapon == NULL)
		weapon_type = "fist";
	else
		weapon_type = this->weapon->getType();
	std::cout << this->name << attack_msg << weapon_type;
	std::cout << std::endl;
}
