#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog( void );
		Dog( const Dog &src );
		virtual ~Dog( void );

		Dog &operator =( const Dog &rhs );

		virtual void makeSound( void ) const;

	private:
		Brain *brain_;
};

#endif //DOG_HPP
