#include <iostream>

static void	str_toupper(char *str)
{
	for (size_t i = 0; str[i] != 0x00; ++i)
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] += 'A' - 'a';
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		str_toupper(av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}

