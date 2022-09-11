#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void mandatoryTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void multipleAssignationTest()
{
	MateriaSource src1;
	MateriaSource src2;
	MateriaSource assigned;

	src1.learnMateria(new Ice());
	src2.learnMateria(new Cure());
	assigned = src1;
	assigned = src2;

	Character a("a");
	Character b("b");
	Character c;

	a.equip(src1.createMateria("ice"));
	b.equip(src2.createMateria("cure"));
	c.equip(src1.createMateria("ice"));
	c.equip(src2.createMateria("cure"));

	c = a;
	c = b;
	b = a;
}

int main()
{
	std::cout << "================== Mandatory Test ================" << std::endl;
	mandatoryTest();
	std::cout << "=============== Leak Test =================" << std::endl;
	multipleAssignationTest();
}
