#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &src );
		virtual ~FragTrap( void );

		FragTrap &operator =( const FragTrap &rhs );

		virtual void attack( const std::string &name );
		void highFivesGuys( void );

	protected:
		const unsigned int kFragHp_;
		const unsigned int kFragEp_;
		const unsigned int kFragAttackDamage_;

	private:
		void setFragMembers( const std::string &name,
					unsigned int hp, unsigned int ep,
					unsigned int attack_dmg );
};

#endif
