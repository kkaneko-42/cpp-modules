#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	const std::string kMsg = ": Diamond default constructor called";
	const std::string kDefaultName = "None";
	const std::string kClapSuffix = "_clap_name";

	ClapTrap::name_ = kDefaultName + kClapSuffix;
	this->DiamondTrap::setDiamondMembers(kDefaultName,
					FragTrap::kFragHp_,
					ScavTrap::kScavEp_,
					FragTrap::kFragAttackDamage_);
	std::cout << this->name_ << kMsg << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(),
													FragTrap(),
													ScavTrap()
{
	const std::string msg = ": Diamond copy constructor called";
	const std::string kClapSuffix = "_clap_name";

	this->DiamondTrap::setDiamondMembers(src.name_,
				src.hp_,
				src.ep_,
				src.attack_damage_);
	std::cout << this->name_ << msg << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name )
{
	const std::string msg = ": Naming constructor called";
	const std::string kClapSuffix = "_clap_name";

	this->DiamondTrap::setDiamondMembers(name,
				FragTrap::kFragHp_,
				ScavTrap::kScavEp_,
				FragTrap::kFragAttackDamage_);
	this->ClapTrap::name_ += kClapSuffix;
	std::cout << this->name_ << msg << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	const std::string msg = ": Destructor called";

	std::cout << this->name_ << msg << std::endl;
}

DiamondTrap &DiamondTrap::operator =( const DiamondTrap &rhs )
{
	const std::string msg = ": Assignation operator called";

	this->name_ = rhs.name_;
	this->hp_ = rhs.hp_;
	this->ep_ = rhs.ep_;
	this->attack_damage_ = rhs.attack_damage_;

	std::cout << this->name_ << msg << std::endl;

	return (*this);
}

void DiamondTrap::setDiamondMembers( const std::string &name,
									unsigned int hp, unsigned int ep,
									unsigned int attack_dmg)
{
	this->name_ = name;
	this->hp_ = hp;
	this->ep_ = ep;
	this->attack_damage_ = attack_dmg;
}

// void DiamondTrap::attack( DiamondTrap &target )
// {
// 	if (!this->isFine())
// 	{
// 		putAlreadyFaintedMsg(this->name_);
// 		return ;
// 	}

// 	std::cout << "DiamondTrap " << this->name_ << " attacks " << target.name_ + ", ";
// 	std::cout << "causing " << this->attack_damage_ << " points of damage!" << std::endl;
// 	target.takeDamage(this->attack_damage_);

// 	this->ep_ -= 1;
// 	if (!this->isFine())
// 		putFaintedMsg(this->name_);
// }

void DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << this->name_ << ": I am " << ClapTrap::name_ << std::endl;
}
