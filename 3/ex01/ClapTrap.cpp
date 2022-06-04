#include <iostream>
#include "ClapTrap.hpp"

static void putFaintedMsg( const std::string &name );
static void putAlreadyFaintedMsg( const std::string &name );

ClapTrap::ClapTrap( void ) : name_("None"),
							hp_(10), ep_(10),
							attack_damage_(10)
{
	const std::string msg = ": Default constructor called";

	std::cout << this->name_ << msg << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	const std::string msg = ": Copy constructor called";

	*this = src;
	std::cout << this->name_ << msg << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ) : name_(name),
												hp_(10), ep_(10),
												attack_damage_(10)
{
	const std::string msg = ": Naming constructor called";

	std::cout << this->name_ << msg << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	const std::string msg = ": Destructor called";

	std::cout << this->name_ << msg << std::endl;
}

ClapTrap &ClapTrap::operator =( const ClapTrap &rhs )
{
	const std::string msg = ": Assignation operator called";

	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	std::cout << this->name_ << msg << std::endl;

	return (*this);
}

// void ClapTrap::attack( ClapTrap &target )
// {
// 	if (!this->isFine())
// 	{
// 		putAlreadyFaintedMsg(this->name_);
// 		return ;
// 	}

// 	std::cout << "ClapTrap " << this->name_ << " attacks " << target.name_ + ", ";
// 	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
// 	target.takeDamage(this->attack_damage_);

// 	this->ep_ -= 1;
// 	if (!this->isFine())
// 		putFaintedMsg(this->name_);
// }

void ClapTrap::attack( const std::string &target )
{
	std::cout << "ClapTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (!this->isFine())
	{
		putAlreadyFaintedMsg(this->name_);
		return ;
	}

	if (this->hp_ <= amount)
		this->hp_ = 0;
	else
		this->hp_ -= amount;

	std::cout << "ClapTrap " << this->name_ << " take damage " << amount << std::endl;
	if (!this->isFine())
		putFaintedMsg(this->name_);
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->isFine())
	{
		putAlreadyFaintedMsg(this->name_);
		return ;
	}

	std::cout << "ClapTrap " << this->name_ << " repairs itself, ";
	std::cout << "and get " << amount << " points" << std::endl;
	this->ep_ -= 1;
	if (!this->isFine())
		putFaintedMsg(this->name_);
}

bool ClapTrap::isFine( void ) const
{
	if (this->hp_ == 0 || this->ep_ == 0)
		return (false);
	else
		return (true);
}

void ClapTrap::setMembers( const std::string &name ,
							unsigned int hp, unsigned int ep,
							unsigned int attack_dmg)
{
	this->name_ = name;
	this->hp_ = hp;
	this->ep_ = ep;
	this->attack_damage_ = attack_dmg;
}

static void putFaintedMsg( const std::string &name )
{
	std::cout << "ClapTrap " << name << " has fainted..." << std::endl;
}

static void putAlreadyFaintedMsg( const std::string &name )
{
	std::cout << "ClapTrap " << name << " has already fainted" << std::endl;
}
