#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap &src );
		ClapTrap( const std::string &name );
		virtual ~ClapTrap( void );

		ClapTrap &operator =( const ClapTrap &rhs );

		virtual void attack( const std::string &target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		bool isFine( void ) const;

	protected:
		std::string name_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int attack_damage_;
		virtual void setMembers( const std::string &name,
								unsigned int hp, unsigned int ep,
								unsigned int attack_dmg );
};

#endif
