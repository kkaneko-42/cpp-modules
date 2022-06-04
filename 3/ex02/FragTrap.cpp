#include <iostream>
#include <string>
#include "FragTrap.hpp"

// static void putFaintedMsg( const std::string &name );
// static void putAlreadyFaintedMsg( const std::string &name );

FragTrap::FragTrap( void ) : ClapTrap()
{
	const std::string msg = ": Frag default constructor called";

	this->setMembers("None", 100, 50, 20);
	std::cout << name_ << msg << std::endl;
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap(src)
{
	const std::string msg = ": Frag copy constructor called";

	*this = src;
	std::cout << name_ << msg << std::endl;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name)
{
	const std::string msg = ": Frag naming constructor called";

	this->setMembers(name, 100, 50, 20);
	std::cout << name_ << msg << std::endl;
}

FragTrap::~FragTrap( void )
{
	const std::string msg = ": Frag destructor called";

	std::cout << name_ << msg << std::endl;
}

FragTrap &FragTrap::operator =( const FragTrap &rhs )
{
	const std::string msg = ": Frag assignation operator called";

	this->setMembers(rhs.name_, rhs.hp_, rhs.ep_, rhs.attack_damage_);
	std::cout << name_ << msg << std::endl;

	return (*this);
}

// void FragTrap::attack( FragTrap &target )
// {
// 	if (!this->isFine())
// 	{
// 		putAlreadyFaintedMsg(this->name_);
// 		return ;
// 	}

// 	std::cout << "FragTrap " << this->name_ << " attacks " << target.name_ + ", ";
// 	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
// 	target.takeDamage(this->attack_damage_);

// 	this->ep_ -= 1;
// 	if (!this->isFine())
// 		putFaintedMsg(this->name_);
// }

void FragTrap::attack( const std::string &target )
{
	std::cout << "FragTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	const std::string msg = " wants to do positive high fives";

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
