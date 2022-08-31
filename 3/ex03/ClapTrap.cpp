#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name_("None"),
							hp_(10), ep_(10),
							attack_damage_(0)
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
												attack_damage_(0)
{
	const std::string msg = ": Naming constructor called";

	std::cout << this->name_ << msg << std::endl;
}

ClapTrap::ClapTrap(
const std::string &name, unsigned int hp,
unsigned int ep, unsigned int dmg ) :
name_(name), hp_(hp), ep_(ep), attack_damage_(dmg)
{}

ClapTrap::~ClapTrap( void )
{
	const std::string msg = ": Destructor called";

	std::cout << this->name_ << msg << std::endl;
}

ClapTrap &ClapTrap::operator =( const ClapTrap &rhs )
{
	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	return (*this);
}

std::ostream &operator <<( std::ostream &os, ClapTrap &ct )
{
	std::cout << "==== " << ct.getName() << "'s info ====" << std::endl;
	std::cout << "HP: " << ct.getHp() << std::endl;
	std::cout << "EP: " << ct.getEp() << std::endl;
	return (os);
}

std::string ClapTrap::getName( void ) const
{
	return (this->name_);
}

unsigned int ClapTrap::getHp( void ) const
{
	return (this->hp_);
}

unsigned int ClapTrap::getEp( void ) const
{
	return (this->ep_);
}

void ClapTrap::attack( const std::string &target )
{
	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name_ << " attacks " << target + ", ";
	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
	this->setEp(this->ep_ - 1);
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (!this->isFine())
	{
		std::cout << name_ << " has already fainted" << std::endl;
		return ;
	}

	std::cout << this->name_ << " take damage " << amount << std::endl;
	if (this->hp_ <= amount)
		amount = this->hp_;
	this->setHp(this->hp_ - amount);
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->isFine())
	{
		std::cout << this->name_ << " has already fainted" << std::endl;
		return ;
	}

	std::cout << this->name_ << " repairs itself, ";
	std::cout << "and get " << amount << " points" << std::endl;
	this->setHp(this->hp_ + amount);
	this->setEp(this->ep_ - 1);
}

bool ClapTrap::isFine( void ) const
{
	if (this->hp_ == 0 || this->ep_ == 0)
		return (false);
	else
		return (true);
}

void ClapTrap::setEp( unsigned int ep )
{
	this->ep_ = ep;
	if (ep == 0)
		std::cout << this->name_ << " has fainted..." << std::endl;
}

void ClapTrap::setHp( unsigned int hp )
{
	this->hp_ = hp;
	if (hp == 0)
		std::cout << this->name_ << " has fainted..." << std::endl;
}

void ClapTrap::setAttackDmg( unsigned int dmg )
{
	this->attack_damage_ = dmg;
}
