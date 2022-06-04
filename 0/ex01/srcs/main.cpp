#include <iostream>
#include <string>
#include "contact.hpp"

static short parse(std::string input);

int main(void)
{
	std::string input;
	void (*cmds[4])(Contact *, size_t *) = {Exit, Add, Search, Invalid};
	short exec_func;
	Contact contacts[8];
	size_t cnt_added = 0;

	std::cout << "Welcome to ft_crappy!" << std::endl;
	while (42)
	{
		std::cout << "Input command: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> input;
		exec_func = parse(input);
		(*cmds[exec_func])(contacts, &cnt_added);
	}
	return (0);
}

static short parse(std::string input)
{
	const std::string exit_cmd = "EXIT";
	const std::string add_cmd = "ADD";
	const std::string search_cmd = "SEARCH";

	if (std::cin.eof() || input == exit_cmd)
		return (0);
	else if (input == add_cmd)
		return (1);
	else if (input == search_cmd)
		return (2);
	else
		return (3);
}
