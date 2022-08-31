#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("None", 100, 50, 20)
{
	const std::string msg = ": Scav default constructor called";

	std::cout << name_ << msg << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap(src)
{
	const std::string msg = ": Scav copy constructor called";

	std::cout << name_ << msg << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name, 100, 50, 20)
{
	const std::string msg = ": Scav naming constructor called";

	std::cout << name_ << msg << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	const std::string msg = ": Scav destructor called";

	std::cout << name_ << msg << std::endl;
}

ScavTrap &ScavTrap::operator =( const ScavTrap &rhs )
{
	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	return (*this);
}

void ScavTrap::attack( const std::string &target )
{
	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
	this->setEp(this->ep_ - 1);
}

void ScavTrap::guardGate( void )
{
	const std::string msg = " is now in Gate keeper mode";

	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return;
	}
	std::cout << this->name_ << msg << std::endl;
}
