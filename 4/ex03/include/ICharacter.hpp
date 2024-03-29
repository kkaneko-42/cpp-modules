#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#define INVENTORY_SIZE 4

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter( void ) {};

		virtual std::string const &getName(void) const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif //ICHARACTER_HPP
