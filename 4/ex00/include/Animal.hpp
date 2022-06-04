#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal( void );
		Animal( const Animal &src );
		Animal( const std::string &type );
		virtual ~Animal( void );

		Animal &operator =( const Animal &rhs );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type_;
};

#endif //ANIMAL_HPP
