#ifndef FragTRAP_HPP
# define FragTRAP_HPP
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

		static const std::string kDefaultName;
		static const unsigned int kDefaultHp;
		static const unsigned int kDefaultEp;
		static const unsigned int kDefaultAttackDmg;
};

#endif
