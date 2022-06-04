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

	protected:
		const unsigned int kScavHp_;
		const unsigned int kScavEp_;
		const unsigned int kScavAttackDamage_;

	private:
		void setScavMembers( const std::string &name,
					unsigned int hp, unsigned int ep,
					unsigned int attack_dmg );
};

#endif
