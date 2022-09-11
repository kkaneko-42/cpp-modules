#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#define LEARN_MAX 4

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &src );
		virtual ~MateriaSource( void );

		MateriaSource &operator =( const MateriaSource &rhs );

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
	
	private:
		AMateria *learned_[LEARN_MAX];
};

#endif //MATERIASOURCE_HPP
