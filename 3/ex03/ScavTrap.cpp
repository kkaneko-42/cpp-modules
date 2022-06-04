#include <iostream>
#include <string>
#include "ScavTrap.hpp"

const unsigned int gInitHp = 100;
const unsigned int gInitEp = 50;
const unsigned int gInitAttackDmg = 20;

// static void putFaintedMsg( const std::string &name );
// static void putAlreadyFaintedMsg( const std::string &name );

// ScavTrap::ScavTrap( void ) : ClapTrap(),
// 								kScavHp_(gInitHp), kScavEp_(gInitEp),
// 								kScavAttackDamage_(gInitAttackDmg)
ScavTrap::ScavTrap( void ) : kScavHp_(gInitHp), kScavEp_(gInitEp),
								kScavAttackDamage_(gInitAttackDmg)
{
	const std::string msg = ": Scav default constructor called";

	this->setScavMembers("None", 100, 50, 20);
	std::cout << name_ << msg << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap(src),
											kScavHp_(gInitHp), kScavEp_(gInitEp),
											kScavAttackDamage_(gInitAttackDmg)
{
	const std::string msg = ": Scav copy constructor called";

	*this = src;
	std::cout << name_ << msg << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name),
												kScavHp_(gInitHp), kScavEp_(gInitEp),
												kScavAttackDamage_(gInitAttackDmg)
{
	const std::string msg = ": Scav naming constructor called";

	this->setScavMembers(name, 100, 50, 20);
	std::cout << name_ << msg << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	const std::string msg = ": Scav destructor called";

	std::cout << name_ << msg << std::endl;
}

ScavTrap &ScavTrap::operator =( const ScavTrap &rhs )
{
	const std::string msg = ": Scav assignation operator called";

	this->setScavMembers(rhs.name_, rhs.hp_, rhs.ep_, rhs.attack_damage_);
	std::cout << name_ << msg << std::endl;

	return (*this);
}

void ScavTrap::setScavMembers( const std::string &name,
									unsigned int hp, unsigned int ep,
									unsigned int attack_dmg)
{
	this->name_ = name;
	this->hp_ = hp;
	this->ep_ = ep;
	this->attack_damage_ = attack_dmg;
}

// void ScavTrap::attack( ScavTrap &target )
// {
// 	if (!this->isFine())
// 	{
// 		putAlreadyFaintedMsg(this->name_);
// 		return ;
// 	}

// 	std::cout << "ScavTrap " << this->name_ << " attacks " << target.name_ + ", ";
// 	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
// 	target.takeDamage(this->attack_damage_);

// 	this->ep_ -= 1;
// 	if (!this->isFine())
// 		putFaintedMsg(this->name_);
// }

void ScavTrap::attack( const std::string &target )
{
	std::cout << "ScavTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
	const std::string msg = " is now in Gate keeper mode";

	std::cout << this->name_ << msg << std::endl;
}

// static void putFaintedMsg( const std::string &name )
// {
// 	std::cout << "ClapTrap " << name << " has fainted..." << std::endl;
// }

// static void putAlreadyFaintedMsg( const std::string &name )
// {
// 	std::cout << "ClapTrap " << name << " has already fainted" << std::endl;
// }
