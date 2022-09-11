#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void mandatoryTest();
static void leakTest();

int main(void)
{
	mandatoryTest();
	leakTest();
	return 0;
}

static void mandatoryTest(void)
{
	const size_t kArrayLen = 10;
	Animal **animals = new Animal*[kArrayLen];
	Dog dogs[kArrayLen / 2];
	Cat cats[kArrayLen / 2];
	size_t i = 0;
	size_t j = 0;

	while (i < kArrayLen / 2)
	{
		animals[i] = &dogs[i];
		++i;
	}
	while (i < kArrayLen)
	{
		animals[i] = &cats[j];
		++i;
		++j;
	}

	for (size_t k = 0; k < kArrayLen; ++k)
	{
		animals[k]->makeSound();
	}
	delete[] animals;
}

static void leakTest(void)
{
	std::cout << "=============== Leak test ====================" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	Cat cat1;
	Cat cat2;
	Cat assigned = cat1;
	assigned = cat2;

	delete dog;
	delete cat;
}
