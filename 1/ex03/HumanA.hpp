#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <string>

class HumanA
{
	public:
		HumanA( std::string name, Weapon &weapon );
		void attack( void );
	private:
		std::string name;
		Weapon &weapon;
};

#endif //HUMAN_A_HPP
