#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{

	public:
		void announce( void );
		void setName( std::string name );
		std::string getName( void );

		~Zombie( void );
	private:
		std::string name_;

};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif //ZOMBIE_HPP