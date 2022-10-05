#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"
#define TEST_KO "\x1b[31mKO\x1b[39m"
#define TEST_OK "\x1b[32mOK\x1b[39m"

static void replaceByListTest() {
    std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << " ";
	list.pop_back();
	std::cout << list.size() << " ";
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);

	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
}

static void mandatoryTest() {
    MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " ";
	mstack.pop();
	std::cout << mstack.size() << " ";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
    
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
    std::cout << "mstack: ";
    mandatoryTest();
    std::cout << std::endl;
    std::cout << "list__: ";
    replaceByListTest();
    std::cout << std::endl;
	return 0;
}
