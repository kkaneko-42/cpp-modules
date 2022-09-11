#include <iostream>
#include "Character.hpp"

static void copyMaterias(AMateria **dst, AMateria **src, size_t n)
{
	if (dst == NULL || src == NULL)
		return;
	for (size_t i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}

static void initInventory(AMateria ***inventory, size_t size)
{
	*inventory = new AMateria*[size];
	for (size_t i = 0; i < size; ++i)
	{
		(*inventory)[i] = NULL;
	}
}

static void deleteMaterias(AMateria **materias, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		delete materias[i];
		materias[i] = NULL;
	}
	delete[] materias;
}

Character::Character( void ) :
name_(""), garbage_(NULL), garbage_size_(0)
{
	initInventory(&inventory_, INVENTORY_SIZE);
}

Character::Character( const Character &src )
{
	initInventory(&inventory_, INVENTORY_SIZE);
	*this = src;
}

Character::Character( const std::string &name ) :
name_(name), garbage_(NULL), garbage_size_(0)
{
	initInventory(&inventory_, INVENTORY_SIZE);
}

Character::~Character( void )
{
	deleteMaterias(inventory_, INVENTORY_SIZE);
	deleteMaterias(garbage_, garbage_size_);
}

Character &Character::operator =( const Character &rhs )
{
	name_ = rhs.name_;
	for (size_t i = 0; i < INVENTORY_SIZE; ++i)
	{
		addGarbage(inventory_[i]);
		if (rhs.inventory_[i] == NULL)
			inventory_[i] = NULL;
		else
			inventory_[i] = rhs.inventory_[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (name_);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (size_t i = 0; i < INVENTORY_SIZE; ++i)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (isInvalidIdx(static_cast<size_t>(idx)))
	{
		std::cerr << getName() << ": unequip idx is invalid" << std::endl;
		return;
	}
	addGarbage(inventory_[idx]);
	inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (isInvalidIdx(static_cast<size_t>(idx)))
	{
		std::cerr << getName() << ": use idx is invalid" << std::endl;
		return;
	}
	inventory_[idx]->use(target);
}

void Character::addGarbage(AMateria *m)
{
	AMateria **new_garbage = new AMateria*[garbage_size_ + 1];

	// copy the old garbage
	copyMaterias(new_garbage, garbage_, garbage_size_);
	// add the new one
	new_garbage[garbage_size_] = m;
	// update the garbage
	delete[] garbage_;
	garbage_ = new_garbage;
	++garbage_size_;
}

bool Character::isInvalidIdx(size_t index)
{
	return (index >= INVENTORY_SIZE || inventory_[index] == NULL);
}
