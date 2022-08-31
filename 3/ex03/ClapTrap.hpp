#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap &src );
		ClapTrap( const std::string &name );
		ClapTrap( const std::string &name, unsigned int hp, unsigned int ep, unsigned int dmg );
		virtual ~ClapTrap( void );

		ClapTrap &operator =( const ClapTrap &rhs );

		std::string getName( void ) const;
		unsigned int getHp( void ) const;
		unsigned int getEp( void ) const;
		virtual void attack( const std::string &string );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		bool isFine( void ) const;

	protected:
		std::string name_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int attack_damage_;
		void setHp( unsigned int hp );
		void setEp( unsigned int ep );
};

std::ostream &operator <<( std::ostream &os, ClapTrap &ct );

#endif
