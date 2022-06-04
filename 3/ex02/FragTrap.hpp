#ifndef FragTRAP_HPP
# define FragTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &src );
		virtual ~FragTrap( void );

		FragTrap &operator =( const FragTrap &rhs );

		virtual void attack( const std::string &name );
		void highFivesGuys( void );
};

#endif
