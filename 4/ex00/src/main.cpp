#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void funcTest(void);

int main(void)
{
	funcTest();
}

static void funcTest(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << w_cat->getType() << " " << std::endl;
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();
	meta->makeSound();
	w_cat->makeSound();
	w_meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete w_meta;
	delete w_cat;
}
