#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin( void ) {return (this->c.begin());}
		iterator end( void ) {return (this->c.end());}

	private:
		typename std::stack<T>::container_type c;
};

#endif //MUTANTSTACK_HPP
