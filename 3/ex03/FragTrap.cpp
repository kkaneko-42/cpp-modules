#include <iostream>
#include <string>
#include "FragTrap.hpp"

const std::string FragTrap::kDefaultName = "None";
const unsigned int FragTrap::kDefaultHp = 100;
const unsigned int FragTrap::kDefaultEp = 100;
const unsigned int FragTrap::kDefaultAttackDmg = 30;

FragTrap::FragTrap( void ) : ClapTrap(kDefaultName, kDefaultHp, kDefaultEp, kDefaultAttackDmg)
{
	const std::string msg = ": Frag default constructor called";

	std::cout << name_ << msg << std::endl;
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap(src)
{
	const std::string msg = ": Frag copy constructor called";

	std::cout << name_ << msg << std::endl;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name, kDefaultHp, kDefaultEp, kDefaultAttackDmg)
{
	const std::string msg = ": Frag naming constructor called";

	std::cout << name_ << msg << std::endl;
}

FragTrap::~FragTrap( void )
{
	const std::string msg = ": Frag destructor called";

	std::cout << name_ << msg << std::endl;
}

FragTrap &FragTrap::operator =( const FragTrap &rhs )
{
	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	return (*this);
}

void FragTrap::attack( const std::string &target )
{
	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
	this->setEp(this->ep_ - 1);
}

void FragTrap::highFivesGuys( void )
{
	const std::string msg = " wants to do positive high fives";

	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return;
	}
	std::cout << this->name_ << msg << std::endl;
}
