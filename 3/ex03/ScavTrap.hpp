#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &src );
		virtual ~ScavTrap( void );

		ScavTrap &operator =( const ScavTrap &rhs );

		virtual void attack( const std::string &name );
		void guardGate( void );

		static const std::string kDefaultName;
		static const unsigned int kDefaultHp;
		static const unsigned int kDefaultEp;
		static const unsigned int kDefaultAttackDmg;
};

#endif
