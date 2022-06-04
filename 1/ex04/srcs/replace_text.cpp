#include <iostream>
#include <string>

static void	do_replace(
	std::string &file_content, const std::string s1,
	const std::string s2, size_t found_i);

void replace_text(
	std::string &file_content, const std::string s1, const std::string s2)
{
	size_t	found_i;

	found_i = file_content.find(s1);
	while (found_i != (size_t)(-1))
	{
		do_replace(file_content, s1, s2, found_i);
		found_i = file_content.find(s1);
	}
}

static void	do_replace(
	std::string &str, const std::string s1,
	const std::string s2, size_t found_i)
{
	str.erase(str.begin() + found_i, str.begin() + found_i + s1.size());
	str.insert(found_i, s2.data());
}
