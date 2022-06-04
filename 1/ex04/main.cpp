#include <iostream>
#include <string>
#include "sed.hpp"

static void	validate_args( int ac, char **av);

int main( int ac, char **av )
{
	std::string file_content;

	validate_args(ac, av);
	file_content = get_file_content(av[1]);
	replace_text(file_content, av[2], av[3]);
	write_to_new_file(file_content, av[1]);
	return (0);
}

static void	validate_args( int ac, char **av)
{
	const std::string arg_err = "Argument error";

	(void)av;
	if (ac != 4)
		exit_with_error(arg_err);
}
