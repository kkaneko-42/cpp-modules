#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <class T>
typename T::iterator easyfind(T &container, typename T::value_type n)
{
	return (std::find(container.begin(), container.end(), n));
}

#endif //EASYFIND_HPP
