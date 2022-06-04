#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap &src );
		DiamondTrap( const std::string &name );
		virtual ~DiamondTrap( void );

		DiamondTrap &operator =( const DiamondTrap &rhs );

		virtual void attack( const std::string &target );
		void whoAmI( void );

	protected:
		std::string name_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int attack_damage_;

	private:
		void setDiamondMembers( const std::string &name,
							unsigned int hp, unsigned int ep,
							unsigned int attack_dmg );
};

#endif
