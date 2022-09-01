#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
ClapTrap(ScavTrap::kDefaultName, FragTrap::kDefaultHp,
	ScavTrap::kDefaultEp, FragTrap::kDefaultAttackDmg),
name_(ClapTrap::name_ + "_clap_name")
{
	const std::string msg = ": Diamond default constructor called";

	std::cout << name_ << msg << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) :
ClapTrap(src), ScavTrap(src), FragTrap(src),
name_(ClapTrap::name_ + "_clap_name")
{
	const std::string msg = ": Diamond copy constructor called";

	std::cout << name_ << msg << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ) :
ClapTrap(name, FragTrap::kDefaultHp,
	ScavTrap::kDefaultEp, FragTrap::kDefaultAttackDmg),
name_(ClapTrap::name_ + "_clap_name")
{
	const std::string msg = ": Diamond naming constructor called";

	std::cout << name << msg << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	const std::string msg = ": Diamond destructor called";

	std::cout << name_ << msg << std::endl;
}

DiamondTrap &DiamondTrap::operator =( const DiamondTrap &rhs )
{
	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	return (*this);
}

void DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << name_ << "'s clap name is " << ClapTrap::name_ << std::endl;
}
