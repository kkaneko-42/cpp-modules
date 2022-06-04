#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap &src );
		ClapTrap( const std::string &name );
		~ClapTrap( void );

		ClapTrap &operator =( const ClapTrap &rhs );

		// void attack( ClapTrap &target );
		void attack( const std::string &string );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		bool isFine( void ) const;

	private:
		std::string name_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int attack_damage_;
		
};

#endif
