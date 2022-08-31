#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
name_("None"),
ClapTrap(this->name_ + "_clap_name", FragTrap::hp_,
ScavTrap::ep_, FragTrap::attack_damage_)
{
	const std::string msg = ": Diamond default constructor called";

	std::cout << name_ << msg << std::endl;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << 
}