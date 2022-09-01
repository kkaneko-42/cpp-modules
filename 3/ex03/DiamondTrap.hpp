#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap &src );
		DiamondTrap( const std::string &name );
		virtual ~DiamondTrap( void );

		DiamondTrap &operator =( const DiamondTrap &rhs );

		virtual void attack( const std::string &target );
		void whoAmI( void );

	private:
		std::string name_;
};

#endif
