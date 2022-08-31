#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap()
{
	const std::string msg = ": Diamond default constructor called";

	this->name_ = this->getName() + "_clap_name";
	this->setHp(FragTrap::hp_);
	this->setEp(ScavTrap::ep_);
	this->setAttackDmg(FragTrap::attack_damage_);
	std::cout << name_ << msg << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(src), FragTrap(), ScavTrap()
{
	const std::string msg = ": Diamond copy constructor called";

	std::cout << name_ << msg << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name), FragTrap(), ScavTrap()
{
	const std::string msg = ": Diamond naming constructor called";

	this->name_ = this->getName() + "_clap_name";
	this->setHp(FragTrap::hp_);
	this->setEp(ScavTrap::ep_);
	this->setAttackDmg(FragTrap::attack_damage_);
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
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << this->name_ << "'s clap name is " << ClapTrap::name_ << std::endl;
}
