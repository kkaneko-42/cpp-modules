#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &src );
		WrongAnimal( const std::string &type );
		virtual ~WrongAnimal( void );

		WrongAnimal &operator =( const WrongAnimal &rhs );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type;
};

#endif //WrongAnimal_HPP
