#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon){}

void HumanA::attack( void )
{
	const std::string attack_msg = " attacks with their ";

	std::cout << this->name << attack_msg << this->weapon.getType();
	std::cout << std::endl;
}
