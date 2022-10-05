#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;

        MutantStack( void ): std::stack<T>() {}
        MutantStack( const MutantStack& other ): std::stack<T>() {
            *this = other;
        }
        ~MutantStack() {}

		iterator begin( void ) { return (this->c.begin()); }
		iterator end( void ) { return (this->c.end()); }
};

#endif //MUTANTSTACK_HPP
