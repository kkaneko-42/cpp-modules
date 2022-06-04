#ifndef ITER_HPP
#define ITER_HPP

template <class T>
void iter(T *array, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; ++i)
		(*f)(array[i]);
}

#endif //ITER_HPP
