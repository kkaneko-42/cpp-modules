#include <iostream>
#include "MateriaSource.hpp"

static void initLearned(AMateria *learned[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
		learned[i] = NULL;
}

MateriaSource::MateriaSource( void )
{
	initLearned(learned_, LEARN_MAX);
}

MateriaSource::MateriaSource( const MateriaSource &src )
{
	initLearned(learned_, LEARN_MAX);
	*this = src;
}

MateriaSource::~MateriaSource( void )
{
	for (size_t i = 0; i < LEARN_MAX; ++i)
	{
		delete learned_[i];
		learned_[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator =( const MateriaSource &rhs )
{
	for (size_t i = 0; i < LEARN_MAX; ++i)
	{
		if (rhs.learned_[i] != NULL)
		{
			delete learned_[i];
			learned_[i] = rhs.learned_[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return;
	for (size_t i = 0; i < LEARN_MAX; ++i)
	{
		if (learned_[i] == NULL)
		{
			learned_[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *res = NULL;

	for (size_t i = 0; i < LEARN_MAX; ++i)
	{
		if (learned_[i] != NULL && learned_[i]->getType() == type)
		{
			res = learned_[i]->clone();
			break;
		}
	}
	return (res);
}
