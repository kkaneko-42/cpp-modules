#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#define INVENTORY_SIZE 4

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character( void );
		Character( const Character &src );
		Character( const std::string &name );
		virtual ~Character( void );

		Character &operator =( const Character &rhs );

		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:
		std::string name_;
		AMateria **inventory_;
		AMateria **garbage_;
		size_t garbage_size_;

		void addGarbage(AMateria *m);
		bool isInvalidIdx(size_t index);
};

#endif //CHARACTER_HPP
