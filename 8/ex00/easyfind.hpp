#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <class T>
typename T::iterator easyfind(T &container, int n)
{
	const typename T::iterator kItEnd = container.end() - 1;
	typename T::iterator it = container.begin();

	std::cout << "start: " << *it << std::endl;
	std::cout << "end: " << *kItEnd << std::endl;
	while (it != kItEnd && *it != n)
		++it;
	return (it);
}

#endif //EASYFIND_HPP
