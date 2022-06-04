#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
	public:
		AAnimal( void );
		AAnimal( const AAnimal &src );
		AAnimal( const std::string &type );
		virtual ~AAnimal( void ) = 0;

		AAnimal &operator =( const AAnimal &rhs );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type_;
};

#endif //AAnimal_HPP
