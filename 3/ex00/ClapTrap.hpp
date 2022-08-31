#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		const static std::string kDefaultName;
		const static unsigned int kDefaultHp;
		const static unsigned int kDefaultEp;
		const static unsigned int kDefaultDmg;

		ClapTrap( void );
		ClapTrap( const ClapTrap &src );
		ClapTrap( const std::string &name );
		~ClapTrap( void );

		ClapTrap &operator =( const ClapTrap &rhs );

		std::string getName( void );
		unsigned int getHp( void );
		unsigned int getEp( void );
		void attack( const std::string &string );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		bool isFine( void ) const;

	private:
		std::string name_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int attack_damage_;
		void setHp( unsigned int hp );
		void setEp( unsigned int ep );
};

std::ostream &operator <<( std::ostream &os, ClapTrap &ct );

#endif
